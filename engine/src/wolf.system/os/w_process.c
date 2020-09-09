#include "w_process.h"
#include <apr-1/apr_general.h>
#include <io/w_io.h>

#ifdef W_PLATFORM_WIN
#include <tlhelp32.h>//for checking process
#include <psapi.h>//list all processes
#endif

size_t w_process_get_count_of_instances(_In_z_ const wchar_t* pProcessName)
{
	size_t _instances = 0;

#if defined W_PLATFORM_WIN

	PROCESSENTRY32 _entry;
	_entry.dwSize = sizeof(PROCESSENTRY32);

	HANDLE _snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (_snapshot)
	{
		if (Process32First(_snapshot, &_entry))
		{
			while (Process32Next(_snapshot, &_entry))
			{
				if (!_wcsicmp(_entry.szExeFile, pProcessName))
				{
					_instances++;
				}
			}
		}
		CloseHandle(_snapshot);
	}

#elif defined W_PLATFORM_OSX

	pid_t pids[2048];
	std::wstring _input_name, _compare_name;
	_input_name = std::wstring(name);
	size_t size = 0;

	int bytes = proc_listpids(PROC_ALL_PIDS, 0, pids, sizeof(pids));
	int n_proc = bytes / sizeof(pids[0]);
	int i;
	for (i = 0; i < n_proc; i++)
	{
		struct proc_bsdinfo proc;
		int st = proc_pidinfo(pids[i], PROC_PIDTBSDINFO, 0, &proc, sizeof(proc));
		if (st == sizeof(proc))
		{
			size = std::strlen(proc.pbi_name);
			if (size > 0)
			{
				_compare_name.resize(size);
				std::mbstowcs(&_compare_name[0], proc.pbi_name, size);
			}

			if (!wcscmp(_input_name.data(), _compare_name.data()))
			{
				_instances++;
			}
		}

#elif defined W_PLATFORM_LINUX

	DIR* dir;
	struct dirent* ent;
	char* endptr;
	char buf[512];
	std::wstring _input_name, _compare_name;
	_input_name = std::wstring(name);
	size_t size = 0;

	if (!(dir = opendir("/proc"))) {
		perror("can't open /proc");
		return num;
	}

	while ((ent = readdir(dir)) != NULL)
	{
		/* if endptr is not a null character, the directory is not
		 * entirely numeric, so ignore it */
		long lpid = strtol(ent->d_name, &endptr, 10);
		if (*endptr != '\0')
		{
			continue;
		}

		/* try to open the cmdline file */
		snprintf(buf, sizeof(buf), "/proc/%ld/cmdline", lpid);
		FILE* fp = fopen(buf, "r");

		if (fp)
		{
			if (fgets(buf, sizeof(buf), fp) != NULL)
			{
				/* check the first token in the file, the program name */
				char* first = strtok(buf, " ");

				size = std::strlen(buf);
				if (size > 0)
				{
					_compare_name.resize(size);
					std::mbstowcs(&_compare_name[0], buf, size);
				}


				auto _tmp = std::string(buf);
				auto pos = _compare_name.find_last_of('/');
				std::wstring _file = _compare_name;
				if (pos != std::wstring::npos)
					_file = _compare_name.substr(pos + 1);
				if (!wcscmp((const wchar_t*)_file.data(), (const wchar_t*)_input_name.data()))
				{
					_instances++;
				}
			}
			fclose(fp);
		}

	}

	closedir(dir);
#endif

	return _instances;
}

W_RESULT w_process_get_name_by_id(
	_Inout_ w_mem_pool pMemPool,
	_In_ unsigned long pProcessID,
	_Inout_ wchar_t** pProcessName)
{
	const char* _trace_info = "w_process_get_process_name_by_id";
	if (!pMemPool)
	{
		W_ASSERT_P(false, "bad args! trace info: %s", _trace_info);
		return W_FAILURE;
	}

#ifdef W_PLATFORM_WIN
	wchar_t* _process_name = w_malloc(
		pMemPool,
		MAX_PATH * sizeof(wchar_t));// = L"<unknown>";
	if (!_process_name)
	{
		W_ASSERT(false, "could allocate memory. trace info: w_process_get_name_by_id");
		return W_FAILURE;
	}

	// Get a handle to the process.
	HANDLE _process = OpenProcess(
		PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE,
		pProcessID);

	// Get the process name.
	if (_process)
	{
		HMODULE _hMod;
		DWORD _needed;

		if (EnumProcessModules(_process, &_hMod, sizeof(_hMod), &_needed))
		{
			GetModuleBaseName(_process, _hMod, _process_name, MAX_PATH);
		}
		CloseHandle(_process);

		size_t _len = wcslen(_process_name);
		*pProcessName = w_malloc(
			pMemPool,
			sizeof(wchar_t) * _len);
		if (*pProcessName)
		{
			*pProcessName = wcscpy(*pProcessName, _process_name);
		}
	}
#else

#endif

	return W_SUCCESS;
}

W_RESULT w_process_print_allW(
	_Inout_ w_mem_pool pMemPool,
	_Inout_ wchar_t** pProcessLists)
{
	const char* _trace_info = "w_process_print_allW";
	if (!pMemPool)
	{
		W_ASSERT_P(false, "bad args! trace info: %s", _trace_info);
		return APR_BADARG;
	}
	char* _process_names = w_malloc(pMemPool, sizeof(char));
	if (!_process_names)
	{
		W_ASSERT_P(false,
			"could not allocate memory for _process_names. trace info: %s", _trace_info);
		return W_FAILURE;
	}
	wchar_t* _process_id_tmp = w_malloc(pMemPool, MAX_PATH);
	if (!_process_id_tmp)
	{
		W_ASSERT_P(false,
			"could not allocate memory for _process_id_tmp. trace info: %s", _trace_info);
		return W_FAILURE;
	}

#ifdef W_PLATFORM_WIN

	DWORD _processes[1024], _needed, _number_of_processes;
	if (!EnumProcesses(_processes, sizeof(_processes), &_needed)) return W_FAILURE;

	// Calculate how many process identifiers were returned.
	_number_of_processes = _needed / sizeof(DWORD);

	// Print the name and process identifier for each process.
	*pProcessLists = w_wstrcat(
		pMemPool,
		*pProcessLists,
		L"Process Name : Process ID\n",
		NULL);

	wchar_t* _process_name = NULL;
	wchar_t* _process_id = NULL;
	W_RESULT _ret;
	const wchar_t* _process_name_unknown = L"<unknown>";
	for (size_t i = 0; i < _number_of_processes; i++)
	{
		_ultow(_processes[i], _process_id_tmp, 10);
		_ret = w_process_get_name_by_id(pMemPool, _processes[i], &_process_name);
		if (_ret)
		{
			_process_name = (wchar_t*)_process_name_unknown;
		}
		//print the process name and id
		*pProcessLists = w_wstrcat(
			pMemPool,
			*pProcessLists,
			_process_name,
			L" : ",
			_process_id_tmp,
			L"\n",
			NULL);
	}

	//w_free(pMemPool, _process_id_tmp);

#endif

	return W_SUCCESS;
}

W_RESULT w_process_print_all(
	_Inout_ w_mem_pool pMemPool,
	_Inout_ char** pProcessLists)
{
	const char* _trace_info = "w_process_print_all";
	if (!pMemPool)
	{
		W_ASSERT_P(false, "bad args! trace info: %s", _trace_info);
		return W_FAILURE;
	}

	wchar_t* _process_lists = L"";
	if (w_process_print_allW(pMemPool, &_process_lists) == W_SUCCESS)
	{
		size_t _len = wcslen(_process_lists);
		size_t _dst_len = 0;
		return w_io_wchar_ptr_to_char_ptr(
			pMemPool,
			_process_lists,
			_len,
			pProcessLists);
	}

	return W_FAILURE;
}

#ifdef W_PLATFORM_WIN

W_RESULT w_process_create(
	_Inout_ w_mem_pool pMemPool,
	_In_z_ const wchar_t* pPathToProcess,
	_In_z_ const wchar_t* pCmdsArg,
	_In_z_ const wchar_t* pCurrentDirectoryPath,
	_In_  DWORD pWaitAfterRunningProcess,
	_In_ DWORD pCreationFlags,
	_Out_ w_process_info* pProcessInfo)
{
	size_t _size = sizeof(STARTUPINFO);
	STARTUPINFO* _startup_info = w_malloc(pMemPool, _size);
	if (!_startup_info)
	{
		return W_FAILURE;
	}
	memset(_startup_info, 0, _size);

	_size = sizeof(PROCESS_INFORMATION);
	PROCESS_INFORMATION* _process_info = w_malloc(pMemPool, _size);
	if (!_process_info)
	{
		return W_FAILURE;
	}
	memset(_process_info, 0, _size);

	if (CreateProcessW(
		(LPCWSTR)pPathToProcess,
		(LPCWSTR)pCmdsArg,
		NULL,
		NULL,
		FALSE,
		pCreationFlags,
		NULL,
		pCurrentDirectoryPath,
		_startup_info,
		_process_info))
	{
		WaitForSingleObject(_process_info->hProcess, pWaitAfterRunningProcess);

		*pProcessInfo = w_malloc(pMemPool, sizeof(w_process_info_t));
		if (*pProcessInfo)
		{
			(*pProcessInfo)->info = _process_info;
			(*pProcessInfo)->error_code = GetLastError();
			return W_SUCCESS;
		}
	}

	//logger.error(L"Process ID: \"{}\" could not run with arg \"{}\" . Error code : \"{}\"", pPathtoProcess, pCmdsArg, GetLastError());
	return W_FAILURE;
}

#endif

W_RESULT w_process_kill_by_id(_In_ unsigned long pProcessID)
{
	W_RESULT _hr = W_SUCCESS;

#ifdef W_PLATFORM_WIN

	// Get a handle to the process.
	HANDLE _process = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pProcessID);

	// Get the process name.
	if (_process)
	{
		if (!TerminateProcess(_process, 0))
		{
			_hr = W_FAILURE;
		}

		CloseHandle(_process);
	}

#else

#endif

	return _hr;
}

W_RESULT w_process_kill_by_info(_In_ w_process_info pProcessInfo)
{
	if (!pProcessInfo || !pProcessInfo->info)
	{
		return APR_BADARG;
	}

	if (!TerminateProcess(pProcessInfo->info->hProcess, 0))
	{
		return W_FAILURE;
	}

	if (!CloseHandle(pProcessInfo->info->hThread))
	{
		return W_FAILURE;
	}
	if (!CloseHandle(pProcessInfo->info->hProcess))
	{
		return W_FAILURE;
	}

	return W_SUCCESS;
}

W_RESULT w_process_info_fini(_Inout_ w_process_info pProcessInfo)
{
	if (!pProcessInfo)
	{
		return APR_BADARG;
	}

#ifdef W_PLATFORM_WIN
	CloseHandle(pProcessInfo->handle);
#endif

	return W_SUCCESS;
}

//DWORD FindProcessId(const char* processname)
//{
//	HANDLE hProcessSnap;
//	PROCESSENTRY32 pe32;
//	DWORD result = NULL;
//
//	// Take a snapshot of all processes in the system.
//	hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
//	if (INVALID_HANDLE_VALUE == hProcessSnap) return(FALSE);
//
//	pe32.dwSize = sizeof(PROCESSENTRY32); // <----- IMPORTANT
//
//	// Retrieve information about the first process,
//	// and exit if unsuccessful
//	if (!Process32First(hProcessSnap, &pe32))
//	{
//		CloseHandle(hProcessSnap);          // clean the snapshot object
//		printf("!!! Failed to gather information on system processes! \n");
//		return(NULL);
//	}
//	LPCSTR pOut;
//
//	do
//	{
//		w_io_wchar_ptr_to_char_ptr(
//			pe32.szExeFile,
//			200,
//			&pOut);
//
//		printf("Checking process %ls\n", pe32.szExeFile);
//		if (0 == strcmp(processname, (pOut)))
//		{
//
//			result = pe32.th32ProcessID;
//			break;
//		}
//	} while (Process32Next(hProcessSnap, &pe32));
//
//	CloseHandle(hProcessSnap);
//
//	return result;
//}





//
//
//bool w_process::kill_all_processes(_In_ std::initializer_list<const wchar_t*> pProcessNames)
//{
//	W_RESULT _hr = W_PASSED;
//
//#ifdef __WIN32
//	DWORD aProcesses[1024], cbNeeded, cProcesses;
//	unsigned int i;
//
//	if (!EnumProcesses(aProcesses, sizeof(aProcesses), &cbNeeded)) return L"";
//
//	// Calculate how many process identifiers were returned.
//	cProcesses = cbNeeded / sizeof(DWORD);
//
//	DWORD _process_id = 0;
//	std::wstring _process_name;
//	for (i = 0; i < cProcesses; i++)
//	{
//		_process_id = aProcesses[i];
//		if (_process_id != 0)
//		{
//			_process_name = get_process_name_by_ID(_process_id);
//			for (auto _name : pProcessNames)
//			{
//				if (wcscmp(_process_name.c_str(), _name) == 0)
//				{
//					if (kill_process_by_ID(_process_id) == W_FAILED)
//					{
//						_hr = W_FAILED;
//					}
//				}
//			}
//
//		}
//	}
//
//#endif
//
//	return _hr == W_PASSED;
//}
//
//bool w_process::force_kill_process_by_name(_In_z_ const std::wstring pProcessName,
//	_In_ const bool pTerminateChildProcesses)
//{
//	std::wstring _cmd = L"taskkill /IM " + pProcessName + L" /F";
//	if (pTerminateChildProcesses)
//	{
//		_cmd += L" /T";
//	}
//	_wsystem(_cmd.c_str());
//	return true;
//}
//
//bool w_process::force_kill_process_by_name_as_admin(
//	_In_z_ const std::wstring pProcessName,
//	_In_z_ const std::wstring pUserNameName,
//	_In_z_ const std::wstring pPassword,
//	_In_ const bool pTerminateChildProcesses)
//{
//	std::wstring _cmd = L"taskkill /IM " + pProcessName +
//		L" /U " + pUserNameName +
//		L" /P " + pPassword +
//		L" /F";
//	if (pTerminateChildProcesses)
//	{
//		_cmd += L" /T";
//	}
//	_wsystem(_cmd.c_str());
//	return true;
//}
//
//bool w_process::force_kill_process(_In_z_ const DWORD pProcessID,
//	_In_ const bool pTerminateChildProcesses)
//{
//	std::wstring _cmd = L"taskkill /PID " + std::to_wstring(pProcessID) + L" /F";
//	if (pTerminateChildProcesses)
//	{
//		_cmd += L" /T";
//	}
//	_wsystem(_cmd.c_str());
//	return true;
//}
//
//bool w_process::force_kill_process_by_name_as_admin(
//	_In_ const DWORD pProcessID,
//	_In_z_ const std::wstring pUserNameName,
//	_In_z_ const std::wstring pPassword,
//	_In_ const bool pTerminateChildProcesses)
//{
//	std::wstring _cmd = L"taskkill /PID " + std::to_wstring(pProcessID) +
//		L" /U " + pUserNameName +
//		L" /P " + pPassword +
//		L" /F";
//	if (pTerminateChildProcesses)
//	{
//		_cmd += L" /T";
//	}
//	_wsystem(_cmd.c_str());
//	return true;
//}
//
//#endif
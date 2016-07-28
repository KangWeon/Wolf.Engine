

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


 /* File created by MIDL compiler version 8.00.0603 */
/* at Thu Jul 28 22:32:17 2016
 */
/* Compiler settings for ..\..\..\dependencies\blackmagic\Blackmagic DeckLink SDK 10.6.4\Win\include\DeckLinkAPI.idl:
    Oicf, W1, Zp8, env=Win64 (32b run), target_arch=AMD64 8.00.0603 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


#ifdef __cplusplus
extern "C"{
#endif 


#include <rpc.h>
#include <rpcndr.h>

#ifdef _MIDL_USE_GUIDDEF_

#ifndef INITGUID
#define INITGUID
#include <guiddef.h>
#undef INITGUID
#else
#include <guiddef.h>
#endif

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8)

#else // !_MIDL_USE_GUIDDEF_

#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        const type name = {l,w1,w2,{b1,b2,b3,b4,b5,b6,b7,b8}}

#endif !_MIDL_USE_GUIDDEF_

MIDL_DEFINE_GUID(IID, LIBID_DeckLinkAPI,0xD864517A,0xEDD5,0x466D,0x86,0x7D,0xC8,0x19,0xF1,0xC0,0x52,0xBB);


MIDL_DEFINE_GUID(IID, IID_IDeckLinkTimecode,0xBC6CFBD3,0x8317,0x4325,0xAC,0x1C,0x12,0x16,0x39,0x1E,0x93,0x40);


MIDL_DEFINE_GUID(IID, IID_IDeckLinkDisplayModeIterator,0x9C88499F,0xF601,0x4021,0xB8,0x0B,0x03,0x2E,0x4E,0xB4,0x1C,0x35);


MIDL_DEFINE_GUID(IID, IID_IDeckLinkDisplayMode,0x3EB2C1AB,0x0A3D,0x4523,0xA3,0xAD,0xF4,0x0D,0x7F,0xB1,0x4E,0x78);


MIDL_DEFINE_GUID(IID, IID_IDeckLink,0xC418FBDD,0x0587,0x48ED,0x8F,0xE5,0x64,0x0F,0x0A,0x14,0xAF,0x91);


MIDL_DEFINE_GUID(IID, IID_IDeckLinkConfiguration,0xCB71734A,0xFE37,0x4E8D,0x8E,0x13,0x80,0x21,0x33,0xA1,0xC3,0xF2);


MIDL_DEFINE_GUID(IID, IID_IDeckLinkEncoderConfiguration,0x138050E5,0xC60A,0x4552,0xBF,0x3F,0x0F,0x35,0x80,0x49,0x32,0x7E);


MIDL_DEFINE_GUID(IID, IID_IDeckLinkDeckControlStatusCallback,0x53436FFB,0xB434,0x4906,0xBA,0xDC,0xAE,0x30,0x60,0xFF,0xE8,0xEF);


MIDL_DEFINE_GUID(IID, IID_IDeckLinkDeckControl,0x8E1C3ACE,0x19C7,0x4E00,0x8B,0x92,0xD8,0x04,0x31,0xD9,0x58,0xBE);


MIDL_DEFINE_GUID(IID, IID_IBMDStreamingDeviceNotificationCallback,0xF9531D64,0x3305,0x4B29,0xA3,0x87,0x7F,0x74,0xBB,0x0D,0x0E,0x84);


MIDL_DEFINE_GUID(IID, IID_IBMDStreamingH264InputCallback,0x823C475F,0x55AE,0x46F9,0x89,0x0C,0x53,0x7C,0xC5,0xCE,0xDC,0xCA);


MIDL_DEFINE_GUID(IID, IID_IBMDStreamingDiscovery,0x2C837444,0xF989,0x4D87,0x90,0x1A,0x47,0xC8,0xA3,0x6D,0x09,0x6D);


MIDL_DEFINE_GUID(IID, IID_IBMDStreamingVideoEncodingMode,0x1AB8035B,0xCD13,0x458D,0xB6,0xDF,0x5E,0x8F,0x7C,0x21,0x41,0xD9);


MIDL_DEFINE_GUID(IID, IID_IBMDStreamingMutableVideoEncodingMode,0x19BF7D90,0x1E0A,0x400D,0xB2,0xC6,0xFF,0xC4,0xE7,0x8A,0xD4,0x9D);


MIDL_DEFINE_GUID(IID, IID_IBMDStreamingVideoEncodingModePresetIterator,0x7AC731A3,0xC950,0x4AD0,0x80,0x4A,0x83,0x77,0xAA,0x51,0xC6,0xC4);


MIDL_DEFINE_GUID(IID, IID_IBMDStreamingDeviceInput,0x24B6B6EC,0x1727,0x44BB,0x98,0x18,0x34,0xFF,0x08,0x6A,0xCF,0x98);


MIDL_DEFINE_GUID(IID, IID_IBMDStreamingH264NALPacket,0xE260E955,0x14BE,0x4395,0x97,0x75,0x9F,0x02,0xCC,0x0A,0x9D,0x89);


MIDL_DEFINE_GUID(IID, IID_IBMDStreamingAudioPacket,0xD9EB5902,0x1AD2,0x43F4,0x9E,0x2C,0x3C,0xFA,0x50,0xB5,0xEE,0x19);


MIDL_DEFINE_GUID(IID, IID_IBMDStreamingMPEG2TSPacket,0x91810D1C,0x4FB3,0x4AAA,0xAE,0x56,0xFA,0x30,0x1D,0x3D,0xFA,0x4C);


MIDL_DEFINE_GUID(IID, IID_IBMDStreamingH264NALParser,0x5867F18C,0x5BFA,0x4CCC,0xB2,0xA7,0x9D,0xFD,0x14,0x04,0x17,0xD2);


MIDL_DEFINE_GUID(CLSID, CLSID_CBMDStreamingDiscovery,0x0CAA31F6,0x8A26,0x40B0,0x86,0xA4,0xBF,0x58,0xDC,0xCA,0x71,0x0C);


MIDL_DEFINE_GUID(CLSID, CLSID_CBMDStreamingH264NALParser,0x7753EFBD,0x951C,0x407C,0x97,0xA5,0x23,0xC7,0x37,0xB7,0x3B,0x52);


MIDL_DEFINE_GUID(IID, IID_IDeckLinkVideoOutputCallback,0x20AA5225,0x1958,0x47CB,0x82,0x0B,0x80,0xA8,0xD5,0x21,0xA6,0xEE);


MIDL_DEFINE_GUID(IID, IID_IDeckLinkInputCallback,0xDD04E5EC,0x7415,0x42AB,0xAE,0x4A,0xE8,0x0C,0x4D,0xFC,0x04,0x4A);


MIDL_DEFINE_GUID(IID, IID_IDeckLinkEncoderInputCallback,0xACF13E61,0xF4A0,0x4974,0xA6,0xA7,0x59,0xAF,0xF6,0x26,0x8B,0x31);


MIDL_DEFINE_GUID(IID, IID_IDeckLinkMemoryAllocator,0xB36EB6E7,0x9D29,0x4AA8,0x92,0xEF,0x84,0x3B,0x87,0xA2,0x89,0xE8);


MIDL_DEFINE_GUID(IID, IID_IDeckLinkAudioOutputCallback,0x403C681B,0x7F46,0x4A12,0xB9,0x93,0x2B,0xB1,0x27,0x08,0x4E,0xE6);


MIDL_DEFINE_GUID(IID, IID_IDeckLinkIterator,0x50FB36CD,0x3063,0x4B73,0xBD,0xBB,0x95,0x80,0x87,0xF2,0xD8,0xBA);


MIDL_DEFINE_GUID(IID, IID_IDeckLinkAPIInformation,0x7BEA3C68,0x730D,0x4322,0xAF,0x34,0x8A,0x71,0x52,0xB5,0x32,0xA4);


MIDL_DEFINE_GUID(IID, IID_IDeckLinkOutput,0xCC5C8A6E,0x3F2F,0x4B3A,0x87,0xEA,0xFD,0x78,0xAF,0x30,0x05,0x64);


MIDL_DEFINE_GUID(IID, IID_IDeckLinkInput,0xAF22762B,0xDFAC,0x4846,0xAA,0x79,0xFA,0x88,0x83,0x56,0x09,0x95);


MIDL_DEFINE_GUID(IID, IID_IDeckLinkEncoderInput,0x270587DA,0x6B7D,0x42E7,0xA1,0xF0,0x6D,0x85,0x3F,0x58,0x11,0x85);


MIDL_DEFINE_GUID(IID, IID_IDeckLinkVideoFrame,0x3F716FE0,0xF023,0x4111,0xBE,0x5D,0xEF,0x44,0x14,0xC0,0x5B,0x17);


MIDL_DEFINE_GUID(IID, IID_IDeckLinkMutableVideoFrame,0x69E2639F,0x40DA,0x4E19,0xB6,0xF2,0x20,0xAC,0xE8,0x15,0xC3,0x90);


MIDL_DEFINE_GUID(IID, IID_IDeckLinkVideoFrame3DExtensions,0xDA0F7E4A,0xEDC7,0x48A8,0x9C,0xDD,0x2D,0xB5,0x1C,0x72,0x9C,0xD7);


MIDL_DEFINE_GUID(IID, IID_IDeckLinkVideoFrameMetadataExtensions,0xD5973DC9,0x6432,0x46D0,0x8F,0x0B,0x24,0x96,0xF8,0xA1,0x23,0x8F);


MIDL_DEFINE_GUID(IID, IID_IDeckLinkVideoInputFrame,0x05CFE374,0x537C,0x4094,0x9A,0x57,0x68,0x05,0x25,0x11,0x8F,0x44);


MIDL_DEFINE_GUID(IID, IID_IDeckLinkVideoFrameAncillary,0x732E723C,0xD1A4,0x4E29,0x9E,0x8E,0x4A,0x88,0x79,0x7A,0x00,0x04);


MIDL_DEFINE_GUID(IID, IID_IDeckLinkEncoderPacket,0xB693F36C,0x316E,0x4AF1,0xB6,0xC2,0xF3,0x89,0xA4,0xBC,0xA6,0x20);


MIDL_DEFINE_GUID(IID, IID_IDeckLinkEncoderVideoPacket,0x4E7FD944,0xE8C7,0x4EAC,0xB8,0xC0,0x7B,0x77,0xF8,0x0F,0x5A,0xE0);


MIDL_DEFINE_GUID(IID, IID_IDeckLinkEncoderAudioPacket,0x49E8EDC8,0x693B,0x4E14,0x8E,0xF6,0x12,0xC6,0x58,0xF5,0xA0,0x7A);


MIDL_DEFINE_GUID(IID, IID_IDeckLinkH265NALPacket,0x639C8E0B,0x68D5,0x4BDE,0xA6,0xD4,0x95,0xF3,0xAE,0xAF,0xF2,0xE7);


MIDL_DEFINE_GUID(IID, IID_IDeckLinkAudioInputPacket,0xE43D5870,0x2894,0x11DE,0x8C,0x30,0x08,0x00,0x20,0x0C,0x9A,0x66);


MIDL_DEFINE_GUID(IID, IID_IDeckLinkScreenPreviewCallback,0xB1D3F49A,0x85FE,0x4C5D,0x95,0xC8,0x0B,0x5D,0x5D,0xCC,0xD4,0x38);


MIDL_DEFINE_GUID(IID, IID_IDeckLinkGLScreenPreviewHelper,0x504E2209,0xCAC7,0x4C1A,0x9F,0xB4,0xC5,0xBB,0x62,0x74,0xD2,0x2F);


MIDL_DEFINE_GUID(IID, IID_IDeckLinkDX9ScreenPreviewHelper,0x2094B522,0xD1A1,0x40C0,0x9A,0xC7,0x1C,0x01,0x22,0x18,0xEF,0x02);


MIDL_DEFINE_GUID(IID, IID_IDeckLinkNotificationCallback,0xb002a1ec,0x070d,0x4288,0x82,0x89,0xbd,0x5d,0x36,0xe5,0xff,0x0d);


MIDL_DEFINE_GUID(IID, IID_IDeckLinkNotification,0x0a1fb207,0xe215,0x441b,0x9b,0x19,0x6f,0xa1,0x57,0x59,0x46,0xc5);


MIDL_DEFINE_GUID(IID, IID_IDeckLinkAttributes,0xABC11843,0xD966,0x44CB,0x96,0xE2,0xA1,0xCB,0x5D,0x31,0x35,0xC4);


MIDL_DEFINE_GUID(IID, IID_IDeckLinkStatus,0x5F558200,0x4028,0x49BC,0xBE,0xAC,0xDB,0x3F,0xA4,0xA9,0x6E,0x46);


MIDL_DEFINE_GUID(IID, IID_IDeckLinkKeyer,0x89AFCAF5,0x65F8,0x421E,0x98,0xF7,0x96,0xFE,0x5F,0x5B,0xFB,0xA3);


MIDL_DEFINE_GUID(IID, IID_IDeckLinkVideoConversion,0x3BBCB8A2,0xDA2C,0x42D9,0xB5,0xD8,0x88,0x08,0x36,0x44,0xE9,0x9A);


MIDL_DEFINE_GUID(IID, IID_IDeckLinkDeviceNotificationCallback,0x4997053B,0x0ADF,0x4CC8,0xAC,0x70,0x7A,0x50,0xC4,0xBE,0x72,0x8F);


MIDL_DEFINE_GUID(IID, IID_IDeckLinkDiscovery,0xCDBF631C,0xBC76,0x45FA,0xB4,0x4D,0xC5,0x50,0x59,0xBC,0x61,0x01);


MIDL_DEFINE_GUID(CLSID, CLSID_CDeckLinkIterator,0x1F2E109A,0x8F4F,0x49E4,0x92,0x03,0x13,0x55,0x95,0xCB,0x6F,0xA5);


MIDL_DEFINE_GUID(CLSID, CLSID_CDeckLinkAPIInformation,0x263CA19F,0xED09,0x482E,0x9F,0x9D,0x84,0x00,0x57,0x83,0xA2,0x37);


MIDL_DEFINE_GUID(CLSID, CLSID_CDeckLinkGLScreenPreviewHelper,0xF63E77C7,0xB655,0x4A4A,0x9A,0xD0,0x3C,0xA8,0x5D,0x39,0x43,0x43);


MIDL_DEFINE_GUID(CLSID, CLSID_CDeckLinkDX9ScreenPreviewHelper,0xCC010023,0xE01D,0x4525,0x9D,0x59,0x80,0xC8,0xAB,0x3D,0xC7,0xA0);


MIDL_DEFINE_GUID(CLSID, CLSID_CDeckLinkVideoConversion,0x7DBBBB11,0x5B7B,0x467D,0xAE,0xA4,0xCE,0xA4,0x68,0xFD,0x36,0x8C);


MIDL_DEFINE_GUID(CLSID, CLSID_CDeckLinkDiscovery,0x1073A05C,0xD885,0x47E9,0xB3,0xC6,0x12,0x9B,0x3F,0x9F,0x64,0x8B);


MIDL_DEFINE_GUID(IID, IID_IDeckLinkEncoderConfiguration_v10_5,0x67455668,0x0848,0x45DF,0x8D,0x8E,0x35,0x0A,0x77,0xC9,0xA0,0x28);


MIDL_DEFINE_GUID(IID, IID_IDeckLinkConfiguration_v10_4,0x1E69FCF6,0x4203,0x4936,0x80,0x76,0x2A,0x9F,0x4C,0xFD,0x50,0xCB);


MIDL_DEFINE_GUID(IID, IID_IDeckLinkConfiguration_v10_2,0xC679A35B,0x610C,0x4D09,0xB7,0x48,0x1D,0x04,0x78,0x10,0x0F,0xC0);


MIDL_DEFINE_GUID(IID, IID_IDeckLinkOutput_v9_9,0xA3EF0963,0x0862,0x44ED,0x92,0xA9,0xEE,0x89,0xAB,0xF4,0x31,0xC7);


MIDL_DEFINE_GUID(IID, IID_IDeckLinkInput_v9_2,0x6D40EF78,0x28B9,0x4E21,0x99,0x0D,0x95,0xBB,0x77,0x50,0xA0,0x4F);


MIDL_DEFINE_GUID(IID, IID_IDeckLinkDeckControlStatusCallback_v8_1,0xE5F693C1,0x4283,0x4716,0xB1,0x8F,0xC1,0x43,0x15,0x21,0x95,0x5B);


MIDL_DEFINE_GUID(IID, IID_IDeckLinkDeckControl_v8_1,0x522A9E39,0x0F3C,0x4742,0x94,0xEE,0xD8,0x0D,0xE3,0x35,0xDA,0x1D);


MIDL_DEFINE_GUID(IID, IID_IDeckLink_v8_0,0x62BFF75D,0x6569,0x4E55,0x8D,0x4D,0x66,0xAA,0x03,0x82,0x9A,0xBC);


MIDL_DEFINE_GUID(IID, IID_IDeckLinkIterator_v8_0,0x74E936FC,0xCC28,0x4A67,0x81,0xA0,0x1E,0x94,0xE5,0x2D,0x4E,0x69);


MIDL_DEFINE_GUID(CLSID, CLSID_CDeckLinkIterator_v8_0,0xD9EDA3B3,0x2887,0x41FA,0xB7,0x24,0x01,0x7C,0xF1,0xEB,0x1D,0x37);


MIDL_DEFINE_GUID(IID, IID_IDeckLinkDeckControl_v7_9,0xA4D81043,0x0619,0x42B7,0x8E,0xD6,0x60,0x2D,0x29,0x04,0x1D,0xF7);


MIDL_DEFINE_GUID(IID, IID_IDeckLinkDisplayModeIterator_v7_6,0x455D741F,0x1779,0x4800,0x86,0xF5,0x0B,0x5D,0x13,0xD7,0x97,0x51);


MIDL_DEFINE_GUID(IID, IID_IDeckLinkDisplayMode_v7_6,0x87451E84,0x2B7E,0x439E,0xA6,0x29,0x43,0x93,0xEA,0x4A,0x85,0x50);


MIDL_DEFINE_GUID(IID, IID_IDeckLinkOutput_v7_6,0x29228142,0xEB8C,0x4141,0xA6,0x21,0xF7,0x40,0x26,0x45,0x09,0x55);


MIDL_DEFINE_GUID(IID, IID_IDeckLinkInput_v7_6,0x300C135A,0x9F43,0x48E2,0x99,0x06,0x6D,0x79,0x11,0xD9,0x3C,0xF1);


MIDL_DEFINE_GUID(IID, IID_IDeckLinkTimecode_v7_6,0xEFB9BCA6,0xA521,0x44F7,0xBD,0x69,0x23,0x32,0xF2,0x4D,0x9E,0xE6);


MIDL_DEFINE_GUID(IID, IID_IDeckLinkVideoFrame_v7_6,0xA8D8238E,0x6B18,0x4196,0x99,0xE1,0x5A,0xF7,0x17,0xB8,0x3D,0x32);


MIDL_DEFINE_GUID(IID, IID_IDeckLinkMutableVideoFrame_v7_6,0x46FCEE00,0xB4E6,0x43D0,0x91,0xC0,0x02,0x3A,0x7F,0xCE,0xB3,0x4F);


MIDL_DEFINE_GUID(IID, IID_IDeckLinkVideoInputFrame_v7_6,0x9A74FA41,0xAE9F,0x47AC,0x8C,0xF4,0x01,0xF4,0x2D,0xD5,0x99,0x65);


MIDL_DEFINE_GUID(IID, IID_IDeckLinkScreenPreviewCallback_v7_6,0x373F499D,0x4B4D,0x4518,0xAD,0x22,0x63,0x54,0xE5,0xA5,0x82,0x5E);


MIDL_DEFINE_GUID(IID, IID_IDeckLinkGLScreenPreviewHelper_v7_6,0xBA575CD9,0xA15E,0x497B,0xB2,0xC2,0xF9,0xAF,0xE7,0xBE,0x4E,0xBA);


MIDL_DEFINE_GUID(IID, IID_IDeckLinkVideoConversion_v7_6,0x3EB504C9,0xF97D,0x40FE,0xA1,0x58,0xD4,0x07,0xD4,0x8C,0xB5,0x3B);


MIDL_DEFINE_GUID(IID, IID_IDeckLinkConfiguration_v7_6,0xB8EAD569,0xB764,0x47F0,0xA7,0x3F,0xAE,0x40,0xDF,0x6C,0xBF,0x10);


MIDL_DEFINE_GUID(IID, IID_IDeckLinkVideoOutputCallback_v7_6,0xE763A626,0x4A3C,0x49D1,0xBF,0x13,0xE7,0xAD,0x36,0x92,0xAE,0x52);


MIDL_DEFINE_GUID(IID, IID_IDeckLinkInputCallback_v7_6,0x31D28EE7,0x88B6,0x4CB1,0x89,0x7A,0xCD,0xBF,0x79,0xA2,0x64,0x14);


MIDL_DEFINE_GUID(CLSID, CLSID_CDeckLinkGLScreenPreviewHelper_v7_6,0xD398CEE7,0x4434,0x4CA3,0x9B,0xA6,0x5A,0xE3,0x45,0x56,0xB9,0x05);


MIDL_DEFINE_GUID(CLSID, CLSID_CDeckLinkVideoConversion_v7_6,0xFFA84F77,0x73BE,0x4FB7,0xB0,0x3E,0xB5,0xE4,0x4B,0x9F,0x75,0x9B);


MIDL_DEFINE_GUID(IID, IID_IDeckLinkInputCallback_v7_3,0xFD6F311D,0x4D00,0x444B,0x9E,0xD4,0x1F,0x25,0xB5,0x73,0x0A,0xD0);


MIDL_DEFINE_GUID(IID, IID_IDeckLinkOutput_v7_3,0x271C65E3,0xC323,0x4344,0xA3,0x0F,0xD9,0x08,0xBC,0xB2,0x0A,0xA3);


MIDL_DEFINE_GUID(IID, IID_IDeckLinkInput_v7_3,0x4973F012,0x9925,0x458C,0x87,0x1C,0x18,0x77,0x4C,0xDB,0xBE,0xCB);


MIDL_DEFINE_GUID(IID, IID_IDeckLinkVideoInputFrame_v7_3,0xCF317790,0x2894,0x11DE,0x8C,0x30,0x08,0x00,0x20,0x0C,0x9A,0x66);


MIDL_DEFINE_GUID(IID, IID_IDeckLinkDisplayModeIterator_v7_1,0xB28131B6,0x59AC,0x4857,0xB5,0xAC,0xCD,0x75,0xD5,0x88,0x3E,0x2F);


MIDL_DEFINE_GUID(IID, IID_IDeckLinkDisplayMode_v7_1,0xAF0CD6D5,0x8376,0x435E,0x84,0x33,0x54,0xF9,0xDD,0x53,0x0A,0xC3);


MIDL_DEFINE_GUID(IID, IID_IDeckLinkVideoFrame_v7_1,0x333F3A10,0x8C2D,0x43CF,0xB7,0x9D,0x46,0x56,0x0F,0xEE,0xA1,0xCE);


MIDL_DEFINE_GUID(IID, IID_IDeckLinkVideoInputFrame_v7_1,0xC8B41D95,0x8848,0x40EE,0x9B,0x37,0x6E,0x34,0x17,0xFB,0x11,0x4B);


MIDL_DEFINE_GUID(IID, IID_IDeckLinkAudioInputPacket_v7_1,0xC86DE4F6,0xA29F,0x42E3,0xAB,0x3A,0x13,0x63,0xE2,0x9F,0x07,0x88);


MIDL_DEFINE_GUID(IID, IID_IDeckLinkVideoOutputCallback_v7_1,0xEBD01AFA,0xE4B0,0x49C6,0xA0,0x1D,0xED,0xB9,0xD1,0xB5,0x5F,0xD9);


MIDL_DEFINE_GUID(IID, IID_IDeckLinkInputCallback_v7_1,0x7F94F328,0x5ED4,0x4E9F,0x97,0x29,0x76,0xA8,0x6B,0xDC,0x99,0xCC);


MIDL_DEFINE_GUID(IID, IID_IDeckLinkOutput_v7_1,0xAE5B3E9B,0x4E1E,0x4535,0xB6,0xE8,0x48,0x0F,0xF5,0x2F,0x6C,0xE5);


MIDL_DEFINE_GUID(IID, IID_IDeckLinkInput_v7_1,0x2B54EDEF,0x5B32,0x429F,0xBA,0x11,0xBB,0x99,0x05,0x96,0xEA,0xCD);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



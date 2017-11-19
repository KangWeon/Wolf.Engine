/*
	Project			 : Wolf Engine. Copyright(c) Pooya Eimandar (http://PooyaEimandar.com) . All rights reserved.
	Source			 : Please direct any bug to https://github.com/PooyaEimandar/Wolf.Engine/issues
	Website			 : http://WolfSource.io
	Name			 : w_frame_buffer.h
	Description		 : create frame buffers
	Comment          :
*/

#ifndef __W_FRAME_BUFFER_H__
#define __W_FRAME_BUFFER_H__

#include "w_graphics_device_manager.h"
#include <w_point.h>

namespace wolf
{
	namespace graphics
	{
		class w_frame_buffer_pimp;
		class w_frame_buffer : public system::w_object
		{
		public:
			W_EXP w_frame_buffer();
			W_EXP virtual ~w_frame_buffer();

			W_EXP HRESULT load(_In_ const std::shared_ptr<w_graphics_device>& pGDevice,
				_In_ const VkRenderPass pRenderPass,
				_In_ std::vector<w_image_view> pImageViewAttachments,
				_In_ w_image_view* pDepthAttachment,
				_In_ const w_point_t& pFrameSize,
				_In_ uint32_t pNumberOfLayers,
				_In_ bool pLoadAsRenderTarget = false);

			W_EXP virtual ULONG release() override;


#pragma region Getters

			W_EXP const VkFramebuffer get_frame_buffer_at(_In_ size_t pIndex) const;
			W_EXP const size_t get_frame_buffers_size() const;
			W_EXP const VkDescriptorImageInfo get_descriptor_info(_In_ size_t pIndex) const;

#pragma endregion

#pragma region Setters


#pragma endregion

		private:
			typedef system::w_object						_super;
			w_frame_buffer_pimp*							_pimp;
		};
	}
}

#endif
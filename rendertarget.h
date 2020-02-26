#pragma once

class RenderTarget
{
    bool create_framebuffer(const vk::PhysicalDevice& pd, const vk::UniqueDevice& dev);

public:
    vk::UniqueDescriptorSetLayout m_descr_layout;
    vk::UniquePipelineLayout m_layout;
    vk::UniquePipeline m_pipeline;

    vk::UniqueShaderModule shader_vert;
    vk::UniqueShaderModule shader_frag;

    vk::UniqueImage m_fb_img;
    vk::UniqueImageView m_fb_view;
    vk::UniqueDeviceMemory m_fb_mem;
    vk::UniqueRenderPass m_renderpass;
    vk::UniqueFramebuffer m_framebuffer;

    glm::ivec2 m_size;

    bool create(const vk::PhysicalDevice& pd, const vk::UniqueDevice& dev, int width, int height);
    void to_texture(const vk::UniqueDevice& dev, const vk::UniqueCommandPool& cmd_pool, const vk::Queue& q);
    void to_render(const vk::UniqueDevice& dev, const vk::UniqueCommandPool& cmd_pool, const vk::Queue& q);
};

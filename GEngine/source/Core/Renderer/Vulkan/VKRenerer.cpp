module;
#include "../../Log.h"
#include "Vulkan/vulkan.hpp";
#include "glfw3.h"
module VKRenderer;

bool VKRenderer::Init(std::string engineName, std::string appName)
{   
    if (!glfwVulkanSupported())
    {
        glfwTerminate();
        GE_CRITICAL("GLFW does not support Vulkan");
        return false;
    }

    m_AppInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    m_AppInfo.pNext = nullptr;
    m_AppInfo.pEngineName = engineName.c_str();
    m_AppInfo.pApplicationName = appName.c_str();
    m_AppInfo.apiVersion = VK_MAKE_API_VERSION(0, 1, 1, 0);

    uint32_t extensionsCount = 0;
    const char** extensions = glfwGetRequiredInstanceExtensions(&extensionsCount);
    if (extensionsCount == 0)
    {
        GE_CRITICAL("no Vulkan extensions found");
        return false;
    }

    VkInstanceCreateInfo createInfo{};
    createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    createInfo.pNext = nullptr;
    createInfo.pApplicationInfo = &m_AppInfo;
    createInfo.enabledExtensionCount = extensionsCount;
    createInfo.ppEnabledExtensionNames = extensions;
    createInfo.enabledLayerCount = 0;
    
    VkResult result = vkCreateInstance(&createInfo, nullptr, &m_Instance);
    if (result != VkResult::VK_SUCCESS)
    {
        GE_CRITICAL("no Vulkan extensions found");
        return false;
    }
    
    uint32_t physicalDevicesCount = 0;
    vkEnumeratePhysicalDevices(m_Instance, &physicalDevicesCount, nullptr);
    if (physicalDevicesCount == 0)
    {
        GE_CRITICAL("No Vulkan capable GPU is found");
        return false;
    }

    std::vector<VkPhysicalDevice> physDevices;
    result = vkEnumeratePhysicalDevices(m_Instance, &physicalDevicesCount, physDevices.data());
    if (result != VkResult::VK_SUCCESS)
    {
        GE_CRITICAL("Enumerate physical devices");
        return false;
    }

    result = glfwCreateWindowSurface(m_Instance, m_Window, nullptr, &m_Surface);
    if (result != VkResult::VK_SUCCESS)
    {
        GE_CRITICAL("Could not create Vulkan surface");
        return false;
    }

    GE_TRACE("Successfuly created vulkan instance");
    return true;
}

void VKRenderer::Cleanup()
{
    vkDestroySurfaceKHR(m_Instance, m_Surface, nullptr);
    vkDestroyInstance(m_Instance, nullptr);
}

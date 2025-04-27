module;
#include "Vulkan/vulkan.hpp";
#include "glfw3.h"
export module VKRenderer;

import <string>;
import <vector>;

export class VKRenderer
{
public:
    VKRenderer(GLFWwindow* window) : m_Window(window) {};
    bool Init(std::string engineName, std::string appName);
    void Cleanup();
private:
    GLFWwindow* m_Window = nullptr;
    VkApplicationInfo m_AppInfo{};
    VkInstance m_Instance{};
    VkSurfaceKHR m_Surface{};
};

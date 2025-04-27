module;
#include "Log.h"
#include "glfw3.h"

module Core.Window;

namespace GEngine
{
    bool Window::Init(unsigned int width, unsigned int height, std::string engineName, std::string appName)
    {
        if (!glfwInit())
        {
            GE_CRITICAL("Could not init glfw");
            return false;
        }

        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

        m_AppName = appName;
        m_Window = glfwCreateWindow(width, height, m_AppName.c_str(), nullptr, nullptr);
        if (!m_Window)
        {
            GE_CRITICAL("Could not create window");
            glfwTerminate();
            return false;
        }
        
        m_Renderer = std::make_unique<VKRenderer>(m_Window);
        if (!m_Renderer->Init(engineName, appName))
        {
            GE_CRITICAL("Could not init Vulkan renderer");
            glfwTerminate();
            return false;
        }

        GE_TRACE("Inited window {} with width {} height {}", m_AppName, width, height);
        return true;
    }

    void Window::Run()
    {
        while (!glfwWindowShouldClose(m_Window))
        {

            glfwPollEvents();
        }
    }

    void Window::Cleanup()
    {
        GE_TRACE("Terminating window");
        m_Renderer->Cleanup();
        glfwDestroyWindow(m_Window);
        glfwTerminate();
    }

}

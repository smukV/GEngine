module;
#include "Log.h"
#include "glfw3.h"

module Core.Window;

namespace GEngine
{
    bool Window::Init(unsigned int width, unsigned int height, std::string title)
    {
        if (!glfwInit())
        {
            GE_CRITICAL("Could not init glfw");
            return false;
        }

        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

        m_Window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
        if (!m_Window)
        {
            GE_CRITICAL("Could not create window");
            glfwTerminate();
            return false;
        }

        GE_TRACE("Inited window {} with width {} height {}", title, width, height);
        return true;
    }

    void Window::Run()
    {
        while (!glfwWindowShouldClose(m_Window))
        {

            glfwPollEvents();
        }
    }

    void Window::Term()
    {
        GE_TRACE("Terminating window");
        glfwDestroyWindow(m_Window);
        glfwTerminate();
    }

}

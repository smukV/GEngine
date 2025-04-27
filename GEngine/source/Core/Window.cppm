module;
#include "glfw3.h"

export module Core.Window;

import VKRenderer;
import <string>;
import <memory>;

export namespace GEngine
{
    class Window
    {
    public:
        bool Init(unsigned int width, unsigned int height, std::string engineName = "Untitled", std::string appName = "Untitled");
        void Run();
        void Cleanup();

    private:
        GLFWwindow* m_Window = nullptr;
        std::string m_AppName;

        std::unique_ptr<::VKRenderer> m_Renderer;
    };
}
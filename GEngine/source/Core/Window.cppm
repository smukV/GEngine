module;
#include "glfw3.h"

export module Core.Window;

import <string>;

export namespace GEngine
{
    class Window
    {
    public:
        bool Init(unsigned int width, unsigned int height, std::string title);
        void Run();
        void Term();

    private:
        GLFWwindow* m_Window = nullptr;
    };
}
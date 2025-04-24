module;

#include "Log.h"

module Core;


int main(int argc, char* argv[])
{
    GEngine::Log::Init();
    auto app = GEngine::CreateApplication();
    GEngine::Window window;
    if (window.Init(1280, 720, "GEngine"))
    {
        window.Run();
        window.Term();
    }
    delete app;
}

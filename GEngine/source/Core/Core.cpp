module;

#include "Log.h"

module Core;


int main(int argc, char* argv[])
{
    GEngine::Log::Init();
    auto app = GEngine::CreateApplication();
    GEngine::Window window;
    if (window.Init(1280, 720, "GEngine", app->GetName()))
    {
        window.Run();
        window.Cleanup();
    }
    delete app;
}

#include <Core/Log.h>
import Core.Application;


class SandBox : public GEngine::Application
{
public:
    SandBox()
    {
        GEngine::Log::GetLogger()->info("Sandbox constructor");
    }
    ~SandBox()
    {
        GEngine::Log::GetLogger()->info("Sandbox destructor");
    }
};

GEngine::Application* GEngine::CreateApplication()
{
    return new SandBox();
}

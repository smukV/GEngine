#include <Core/Log.h>
import Core.Application;


class SandBox : public GEngine::Application
{
public:
    SandBox()
    {
        GE_INFO("Sandbox constructor");
    }
    ~SandBox()
    {
        GE_INFO("Sandbox destructor");
    }
};

GEngine::Application* GEngine::CreateApplication()
{
    return new SandBox();
}

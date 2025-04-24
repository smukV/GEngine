#include <Core/Log.h>
import Core.Application;


class SandBox : public GEngine::Application
{
public:
    SandBox() : Application("SandBox")
    {
        GE_APP_INFO("Sandbox constructor");
    }

    ~SandBox()
    {
        GE_APP_INFO("Sandbox destructor");
    }
};

GEngine::Application* GEngine::CreateApplication()
{
    return new SandBox();
}

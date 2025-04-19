#include "spdlog\spdlog.h"
import Core.Application;

class SandBox : public GEngine::Application
{
public:
    SandBox()
    {
        spdlog::info("Sandbox constructor");
    }
    ~SandBox()
    {
        spdlog::info("Sandbox destructor");
    }
};

GEngine::Application* GEngine::CreateApplication()
{
    return new SandBox();
}


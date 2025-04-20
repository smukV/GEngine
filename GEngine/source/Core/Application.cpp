module;

#include "Log.h""

module Core.Application;

namespace GEngine 
{

    Application::Application()
    {
        GEngine::Log::GetLogger()->info("Application constructor");
    }

    Application::~Application()
    {
        GEngine::Log::GetLogger()->info("Application destructor");
    }

}

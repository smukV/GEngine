module;

#include "Log.h""

module Core.Application;

namespace GEngine 
{

    Application::Application()
    {
        GE_INFO("Application constructor");
    }

    Application::~Application()
    {
        GE_INFO("Application destructor");
    }

}

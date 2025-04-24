module;

#include "Log.h"

module Core.Application;

namespace GEngine 
{

    Application::Application(std::string appName) : m_Name(appName)
    {
        GE_INFO("Application {} constructor", m_Name);
        GEngine::Log::InitApp(m_Name);
    }

    Application::~Application()
    {
        GE_INFO("Application destructor");
    }

}

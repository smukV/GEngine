module;

#include <spdlog\spdlog.h>

module Core.Application;

GEngine::Application::Application()
{
    spdlog::info("Application constructor");
}

GEngine::Application::~Application()
{
    spdlog::info("Application destructor");
}

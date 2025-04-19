module;

#include <spdlog\spdlog.h>

module Core;

GEngine::Application::Application()
{
    spdlog::info("Application constructor");
}

GEngine::Application::~Application()
{
    spdlog::info("Application destructor");
}

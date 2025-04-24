#include "Log.h"

#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>

namespace GEngine
{
    std::shared_ptr<spdlog::logger> Log::s_Logger;
    std::shared_ptr<spdlog::logger> Log::s_AppLogger;

    void InitImpl(std::shared_ptr<spdlog::logger> logger)
    {
        #ifdef Debug
            logger->set_level(spdlog::level::trace);
        #endif

        #ifdef Profile
            logger->set_level(spdlog::level::info);
        #endif

        #ifdef Release
            logger->set_level(spdlog::level::critical);
        #endif
    }

    void Log::Init()
    {
        spdlog::set_pattern("%^[%T] %n: %v%$");
        s_Logger = spdlog::stdout_color_mt("GEngine");

        InitImpl(s_Logger);
        GE_TRACE("Core Log Inited");
    }

    void Log::InitApp(std::string appName)
    {
        spdlog::set_pattern("%^[%T] %n: %v%$");
        s_AppLogger = spdlog::stdout_color_mt(appName);

        InitImpl(s_AppLogger);
        GE_APP_TRACE("App Log Inited");
    }

}

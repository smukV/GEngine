#include "Log.h"

#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>

namespace GEngine
{
    std::shared_ptr<spdlog::logger> Log::s_Logger;

    void Log::Init()
    {
        spdlog::set_pattern("%^[%T] %n: %v%$");
        s_Logger = spdlog::stdout_color_mt("GEngine");

        #ifdef Debug
            s_Logger->set_level(spdlog::level::trace);
        #endif

        #ifdef Profile
            s_Logger->set_level(spdlog::level::info);
        #endif

        #ifdef Release
            s_Logger->set_level(spdlog::level::critical);
        #endif

        GE_TRACE("Log Inited");
    }

}

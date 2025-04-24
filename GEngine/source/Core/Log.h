#pragma once
#include <spdlog/spdlog.h>

namespace GEngine
{
    class Log
    {
    public:
        static void Init();
        static void InitApp(std::string appName);

        static inline std::shared_ptr<spdlog::logger> GetLogger() { return s_Logger; }
        static inline std::shared_ptr<spdlog::logger> GetAppLogger() { return s_AppLogger; }

    private:
        static std::shared_ptr<spdlog::logger> s_Logger;
        static std::shared_ptr<spdlog::logger> s_AppLogger;
    };

}

// Log macros

#define GE_TRACE(...)        ::GEngine::Log::GetLogger()->trace(__VA_ARGS__)
#define GE_INFO(...)         ::GEngine::Log::GetLogger()->info(__VA_ARGS__)
#define GE_WARN(...)         ::GEngine::Log::GetLogger()->warn(__VA_ARGS__)
#define GE_ERROR(...)        ::GEngine::Log::GetLogger()->error(__VA_ARGS__)
#define GE_CRITICAL(...)     ::GEngine::Log::GetLogger()->critical(__VA_ARGS__)

#define GE_APP_TRACE(...)    ::GEngine::Log::GetAppLogger()->trace(__VA_ARGS__)
#define GE_APP_INFO(...)     ::GEngine::Log::GetAppLogger()->info(__VA_ARGS__)
#define GE_APP_WARN(...)     ::GEngine::Log::GetAppLogger()->warn(__VA_ARGS__)
#define GE_APP_ERROR(...)    ::GEngine::Log::GetAppLogger()->error(__VA_ARGS__)
#define GE_APP_CRITICAL(...) ::GEngine::Log::GetAppLogger()->critical(__VA_ARGS__)

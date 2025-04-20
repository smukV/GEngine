#pragma once
#include <spdlog/spdlog.h>

namespace GEngine
{
	class Log
	{
	public:
		static void Init();

		static inline std::shared_ptr<spdlog::logger> GetLogger() { return s_Logger; }

	private:
		static std::shared_ptr<spdlog::logger> s_Logger;
	};
}

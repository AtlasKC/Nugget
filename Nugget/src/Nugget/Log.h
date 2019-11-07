#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Nugget
{
	class NUGGET_API Log
	{
	public:
		static void init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

#define NE_CORE_TRACE(...) ::Nugget::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define NE_CORE_INFO(...)  ::Nugget::Log::GetCoreLogger()->info(__VA_ARGS__)
#define NE_CORE_WARN(...)  ::Nugget::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define NE_CORE_ERROR(...) ::Nugget::Log::GetCoreLogger()->error(__VA_ARGS__)
#define NE_CORE_FATAL(...) ::Nugget::Log::GetCoreLogger()->fatal(__VA_ARGS__)

#define NE_TRACE(...) ::Nugget::Log::GetClientLogger()->trace(__VA_ARGS__)
#define NE_INFO(...)  ::Nugget::Log::GetClientLogger()->info(__VA_ARGS__)
#define NE_WARN(...)  ::Nugget::Log::GetClientLogger()->warn(__VA_ARGS__)
#define NE_ERROR(...) ::Nugget::Log::GetClientLogger()->error(__VA_ARGS__)
#define NE_FATAL(...) ::Nugget::Log::GetClientLogger()->fatal(__VA_ARGS__)
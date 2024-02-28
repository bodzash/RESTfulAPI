#pragma once
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

class Logger
{
public:
    static void Init();
    inline static std::shared_ptr<spdlog::logger>& GetLogger() { return sLogger; }

private:
    static std::shared_ptr<spdlog::logger> sLogger;
};

#ifdef RA_ENABLE_LOGGING
    #define RA_TRACE(...) ::Logger::GetLogger()->trace(__VA_ARGS__)
    #define RA_INFO(...)  ::Logger::GetLogger()->info(__VA_ARGS__)
    #define RA_WARN(...)  ::Logger::GetLogger()->warn(__VA_ARGS__)
    #define RA_ERROR(...) ::Logger::GetLogger()->error(__VA_ARGS__)
    #define RA_FATAL(...) ::Logger::GetLogger()->critical(__VA_ARGS__)
#else
    #define RA_TRACE(...) 
    #define RA_INFO(...) 
    #define RA_WARN(...) 
    #define RA_ERROR(...) 
    #define RA_FATAL(...) 
#endif
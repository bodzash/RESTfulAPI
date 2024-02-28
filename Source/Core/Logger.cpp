#include "Logger.h"
#include "spdlog/sinks/stdout_color_sinks.h"

std::shared_ptr<spdlog::logger> Logger::sLogger;

void Logger::Init()
{
    spdlog::set_pattern("%^[%T] %n: %v%$");

    sLogger = spdlog::stdout_color_mt("RESTAPI");
    sLogger->set_level(spdlog::level::trace);
}
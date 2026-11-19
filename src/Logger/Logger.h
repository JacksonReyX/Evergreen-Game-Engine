#pragma once

#ifdef _MSC_VER
#pragma warning(suppress : 4996)
#endif

#include <vector>
#include <string>

enum class LogType {
    LOG_INFO,
    LOG_WARNING,
    LOG_ERROR
};

struct LogEntry {
    LogType type;
    std::string message;
};

class Logger {
public:
    static std::vector<LogEntry> messages_;
    static void Log(const std::string& message);
    static void Err(const std::string& message);
};

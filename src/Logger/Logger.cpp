#include "Logger.h"
#include <iostream>
#include <string>
#include <chrono>
#include <ctime>


std::vector<LogEntry> Logger::messages_;

std::string currentDateTimeToString() {

    auto now = std::chrono::system_clock::now();
    std::time_t now_c = std::chrono::system_clock::to_time_t(now);

    std::tm local_tm{};

#ifdef _WIN32
    localtime_s(&local_tm, &now_c);
#else
    localtime_r(&now_c, &local_tm);
#endif

    std::string output(30, '\0');
    std::strftime(&output[0], output.size(), "%d-%b-%Y %H:%M:%S", &local_tm);
    return output;
}

void Logger::Log(const std::string& message) {
    LogEntry logEntry;
    logEntry.type = LogType::LOG_INFO;
    logEntry.message = "LOG: [" + currentDateTimeToString() + "]: " + message;
    std::cout << "\x1B[32m" << logEntry.message << "\033[0m" << std::endl;
    messages_.push_back(logEntry);
}

void Logger::Err(const std::string& message) {
    LogEntry logEntry;
    logEntry.type = LogType::LOG_ERROR;
    logEntry.message = "ERR: [" + currentDateTimeToString() + "]: " + message;
    messages_.push_back(logEntry);
    std::cerr << "\x1B[91m" << logEntry.message << "\033[0m" << std::endl;
}

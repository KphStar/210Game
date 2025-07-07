#pragma once
#include <fstream>
#include <string>

class Logger {
    std::ofstream ofs;
public:
    Logger(const std::string& filename);
    void log(const std::string& entry);
};
// The Logger class is responsible for logging messages to a file.
#include "Logger.h"

Logger::Logger(const std::string& filename)
  : ofs(filename, std::ios::app)
{}

void Logger::log(const std::string& entry) {
    if (ofs) {
        ofs << entry << "\n";
    }
}

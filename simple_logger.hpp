#ifndef  LOGGER_SIMPLELOGGER_HPP
#define  LOGGER_SIMPLELOGGER_HPP

#include <cstdarg>

#include "logger.hpp"

namespace logger {
  class SimpleLogger : public Logger {
  protected:
    std::string name;
    loglevel level;

    void print(loglevel level, const char * msg);
    void print(loglevel level, const std::string& format, va_list list);
    void print(loglevel level, const std::string& msg, const std::exception& e);

  public:
    SimpleLogger(const std::string& name);
    SimpleLogger(const std::string& name, loglevel level);

    std::string getName() override;

    void trace(const char* msg) override;
    void trace(const std::string& format, ...) override;
    void trace(const std::string& msg, const std::exception& e) override;

    void debug(const char* msg) override;
    void debug(const std::string& format, ...) override;
    void debug(const std::string& msg, const std::exception& e) override;

    void info(const char* msg) override;
    void info(const std::string& format, ...) override;
    void info(const std::string& msg, const std::exception& e) override;

    void warn(const char* msg) override;
    void warn(const std::string& format, ...) override;
    void warn(const std::string& msg, const std::exception& e) override;

    void error(const char* msg) override;
    void error(const std::string& format, ...) override;
    void error(const std::string& msg, const std::exception& e) override;

    void fatal(const char* msg) override;
    void fatal(const std::string& format, ...) override;
    void fatal(const std::string& msg, const std::exception& e) override;

    bool isTraceEnabled() override;
    bool isDebugEnabled() override;
    bool isInfoEnabled() override;
    bool isWarnEnabled() override;
    bool isErrorEnabled() override;
    bool isFatalEnabled() override;
  };

  inline SimpleLogger::SimpleLogger(const std::string& name) {
    this->name = name;
    this->level = Logger::DEFAULT_LOG_LEVEL;
  }

  inline SimpleLogger::SimpleLogger(const std::string& name, loglevel level) {
    this->name = name;
    this->level = level;
  }

  inline std::string SimpleLogger::getName() {
    return name;
  }



  inline bool SimpleLogger::isTraceEnabled() {
    return level >= TRACE;
  }

  inline bool SimpleLogger::isDebugEnabled() {
    return level >= DEBUG;
  }

  inline bool SimpleLogger::isInfoEnabled() {
    return level >= INFO;
  }

  inline bool SimpleLogger::isWarnEnabled() {
    return level >= WARN;
  }

  inline bool SimpleLogger::isErrorEnabled() {
    return level >= ERROR;
  }

  inline bool SimpleLogger::isFatalEnabled() {
    return level >= FATAL;
  }
}

#endif// LOGGER_SIMPLELOGGER_HPP


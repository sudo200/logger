#ifndef  LOGGER_LOGGER_HPP
#define  LOGGER_LOGGER_HPP

#include <string>
#include <exception>

namespace logger {
    typedef enum {
      TRACE = 5,
      DEBUG = 4,
      INFO = 3,
      WARN = 2,
      ERROR = 1,
      FATAL = 0,
    } loglevel;
    static const char * loglevelToString[] = {
      "FATAL",
      "ERROR",
      "WARN",
      "INFO",
      "DEBUG",
      "TRACE",
    };

  /*abstract*/ class Logger {
  public:
    static const loglevel DEFAULT_LOG_LEVEL = INFO;


    virtual std::string getName() = 0;

    virtual void trace(const char * msg) = 0;
    virtual void trace(const std::string& format, ...) = 0;
    virtual void trace(const std::string& msg, const std::exception& e) = 0;

    virtual void debug(const char * msg) = 0;
    virtual void debug(const std::string& format, ...) = 0;
    virtual void debug(const std::string& msg, const std::exception& e) = 0;

    virtual void info(const char * msg) = 0;
    virtual void info(const std::string& format, ...) = 0;
    virtual void info(const std::string& msg, const std::exception& e) = 0;

    virtual void warn(const char * msg) = 0;
    virtual void warn(const std::string& format, ...) = 0;
    virtual void warn(const std::string& msg, const std::exception& e) = 0;

    virtual void error(const char * msg) = 0;
    virtual void error(const std::string& format, ...) = 0;
    virtual void error(const std::string& msg, const std::exception& e) = 0;

    virtual void fatal(const char * msg) = 0;
    virtual void fatal(const std::string& format, ...) = 0;
    virtual void fatal(const std::string& msg, const std::exception& e) = 0;

    virtual bool isTraceEnabled() = 0;
    virtual bool isDebugEnabled() = 0;
    virtual bool isInfoEnabled() = 0;
    virtual bool isWarnEnabled() = 0;
    virtual bool isErrorEnabled() = 0;
    virtual bool isFatalEnabled() = 0;

    virtual ~Logger() {};
  };
}

#endif// LOGGER_LOGGER_HPP


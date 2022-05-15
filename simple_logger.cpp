#include <iostream>
#include <cstdarg>

#include "simple_logger.hpp"

namespace logger {
  void SimpleLogger::print(loglevel level, const char * msg) {
    if(this->level < level)
      return;

    (level >= INFO ? std::cout : std::cerr) << '[' << loglevelToString[level] << ']' << ' '
	<< '[' << name << ']' << ' '
	<< msg << '\n';
  }

  void SimpleLogger::print(loglevel level, const std::string& format, va_list list) {
    char ** str = new char *;

    vasprintf(str, format.c_str(), list);
    print(level, *str);

    free(*str);
    delete str;
  }

  void SimpleLogger::print(loglevel level, const std::string& msg, const std::exception& e) {
    auto message = new std::string(msg);
    (*message) += ": ";
    (*message) += e.what();
    print(level, message->c_str());
    delete message;
  }
  
  void SimpleLogger::trace(const char * msg) {
    print(TRACE, msg);
  }

  void SimpleLogger::trace(const std::string& format, ...) {
    va_list l;
    va_start(l, format);
    print(TRACE, format, l);
    va_end(l);
  }

  void SimpleLogger::trace(const std::string& msg, const std::exception& e) {
    print(TRACE, msg, e);
  }

  
  void SimpleLogger::debug(const char * msg) {
    print(DEBUG, msg);
  }

  void SimpleLogger::debug(const std::string& format, ...) {
    va_list l;
    va_start(l, format);
    print(DEBUG, format, l);
    va_end(l);
  }

  void SimpleLogger::debug(const std::string& msg, const std::exception& e) {
    print(DEBUG, msg, e);
  }


  void SimpleLogger::info(const char * msg) {
    print(INFO, msg);
  }

  void SimpleLogger::info(const std::string& format, ...) {
    va_list l;
    va_start(l, format);
    print(INFO, format, l);
    va_end(l);
  }

  void SimpleLogger::info(const std::string& msg, const std::exception& e) {
    print(INFO, msg, e);
  }


  void SimpleLogger::warn(const char * msg) {
    print(WARN, msg);
  }

  void SimpleLogger::warn(const std::string& format, ...) {
    va_list l;
    va_start(l, format);
    print(WARN, format, l);
    va_end(l);
  }

  void SimpleLogger::warn(const std::string& msg, const std::exception& e) {
    print(WARN, msg, e);
  }


  void SimpleLogger::error(const char * msg) {
    print(ERROR, msg);
  }

  void SimpleLogger::error(const std::string& format, ...) {
    va_list l;
    va_start(l, format);
    print(ERROR, format, l);
    va_end(l);
  }

  void SimpleLogger::error(const std::string& msg, const std::exception& e) {
    print(ERROR, msg, e);
  }


  void SimpleLogger::fatal(const char * msg) {
    print(FATAL, msg);
  }

  void SimpleLogger::fatal(const std::string& format, ...) {
    va_list l;
    va_start(l, format);
    print(FATAL, format, l);
    va_end(l);
  }

  void SimpleLogger::fatal(const std::string& msg, const std::exception& e) {
    print(FATAL, msg, e);
  }
}


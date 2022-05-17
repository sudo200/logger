#include <iostream>
#include <cstdarg>
#include <cstring>

#include "simple_logger.hpp"

#ifdef _MSC_VER
#define vscprintf _vscprintf
#endif

#ifdef __GNUC__

int vscprintf(const char *format, va_list ap) {
    va_list ap_copy;
    va_copy(ap_copy, ap);
    int retval = vsnprintf(NULL, 0, format, ap_copy);
    va_end(ap_copy);
    return retval;
}

#endif

/*
 * asprintf, vasprintf:
 * MSVC does not implement these, thus we implement them here
 * GNU-C-compatible compilers implement these with the same names, thus we
 * don't have to do anything
 */
#ifndef __linux__

int vasprintf(char **strp, const char *format, va_list ap) {
    int len = vscprintf(format, ap);
    if (len == -1)
        return -1;
    char *str = (char *) malloc((size_t) len + 1);
    if (!str)
        return -1;
    int retval = vsnprintf(str, len + 1, format, ap);
    if (retval == -1) {
        free(str);
        return -1;
    }
    *strp = str;
    return retval;
}

int asprintf(char **strp, const char *format, ...) {
    va_list ap;
    va_start(ap, format);
    int retval = vasprintf(strp, format, ap);
    va_end(ap);
    return retval;
}

#endif

namespace logger {
    void SimpleLogger::print(loglevel level, const char *msg) {
        if (this->level < level)
            return;

        (level >= INFO ? std::cout : std::cerr) << '[' << loglevelToString[level] << ']' << ' '
                                                << '[' << name << ']' << ' '
                                                << msg << '\n';
    }

    void SimpleLogger::print(loglevel level, const std::string &format, va_list list) {
        if (this->level < level)
            return;
        char **str = new char *;

        vasprintf(str, format.c_str(), list);
        print(level, *str);

        free(*str);
        delete str;
    }

    void SimpleLogger::print(loglevel level, const std::string &msg, const std::exception &e) {
        if (this->level < level)
            return;
        auto message = new std::string(msg);
        (*message) += ": ";
        (*message) += e.what();
        print(level, message->c_str());
        delete message;
    }

    void SimpleLogger::trace(const char *msg) {
        print(TRACE, msg);
    }

    void SimpleLogger::trace(const std::string &format, ...) {
        va_list l;
        va_start(l, format);
        print(TRACE, format, l);
        va_end(l);
    }

    void SimpleLogger::trace(const std::string &msg, const std::exception &e) {
        print(TRACE, msg, e);
    }


    void SimpleLogger::debug(const char *msg) {
        print(DEBUG, msg);
    }

    void SimpleLogger::debug(const std::string &format, ...) {
        va_list l;
        va_start(l, format);
        print(DEBUG, format, l);
        va_end(l);
    }

    void SimpleLogger::debug(const std::string &msg, const std::exception &e) {
        print(DEBUG, msg, e);
    }


    void SimpleLogger::info(const char *msg) {
        print(INFO, msg);
    }

    void SimpleLogger::info(const std::string &format, ...) {
        va_list l;
        va_start(l, format);
        print(INFO, format, l);
        va_end(l);
    }

    void SimpleLogger::info(const std::string &msg, const std::exception &e) {
        print(INFO, msg, e);
    }


    void SimpleLogger::warn(const char *msg) {
        print(WARN, msg);
    }

    void SimpleLogger::warn(const std::string &format, ...) {
        va_list l;
        va_start(l, format);
        print(WARN, format, l);
        va_end(l);
    }

    void SimpleLogger::warn(const std::string &msg, const std::exception &e) {
        print(WARN, msg, e);
    }


    void SimpleLogger::error(const char *msg) {
        print(ERROR, msg);
    }

    void SimpleLogger::error(const std::string &format, ...) {
        va_list l;
        va_start(l, format);
        print(ERROR, format, l);
        va_end(l);
    }

    void SimpleLogger::error(const std::string &msg, const std::exception &e) {
        print(ERROR, msg, e);
    }


    void SimpleLogger::fatal(const char *msg) {
        print(FATAL, msg);
    }

    void SimpleLogger::fatal(const std::string &format, ...) {
        va_list l;
        va_start(l, format);
        print(FATAL, format, l);
        va_end(l);
    }

    void SimpleLogger::fatal(const std::string &msg, const std::exception &e) {
        print(FATAL, msg, e);
    }
}


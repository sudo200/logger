#include "simple_logger.hpp"

#ifdef __linux__
#define USERNAME    "USER"
#else
#define USERNAME    "USERNAME"
#endif

using namespace logger;

class testexception : public std::exception {
    const char * what() const noexcept {
        return "This was a test!";
    }
};

int main() {
  Logger* logger = new SimpleLogger("main", logger::TRACE);

  logger->trace("Msg");
  logger->trace("Hello %s!", getenv(USERNAME));

  try {
      throw testexception();
  } catch (std::exception& e) {
      logger->error("Exception thrown", e);
  }

  delete logger;
  return 0;
}


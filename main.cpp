#include "simple_logger.hpp"

using namespace logger;

int main() {
  Logger* logger = new SimpleLogger("main");

  logger->trace("This is at trace level!");
  logger->debug("This is at debug level!");
  logger->info("This is at info level!");
  logger->warn("This is at warn level!");
  logger->error("This is at error level!");
  logger->fatal("This is at fatal level!");

  delete logger;

  return 0;
}


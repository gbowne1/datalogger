#include "logger.h"

int main(void) {
    logger_init("app.log");
    LOG(LOG_INFO, "Application started");
    LOG(LOG_DEBUG, "Value: %d", 42);
    logger_close();
    return 0;
}

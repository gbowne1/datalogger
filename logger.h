#ifndef LOGGER_H
#define LOGGER_H

#define _XOPEN_SOURCE 600
#include <stdio.h>

typedef enum {
    LOG_DEBUG,
    LOG_INFO,
    LOG_WARN,
    LOG_ERROR
} log_level_t;

void logger_init(const char *filename);
void logger_log(log_level_t level, const char *file, int line, const char *fmt, ...);
void logger_close(void);

#define LOG(level, ...) \
    logger_log(level, __FILE__, __LINE__, __VA_ARGS__)

#endif /* LOGGER_H */

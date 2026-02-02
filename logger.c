
#include "logger.h"
#include <time.h>
#include <stdarg.h>
#include <string.h>

static FILE *log_file = NULL;

void logger_init(const char *filename) {
    if (filename) {
        log_file = fopen(filename, "a");
    }
}

void logger_log(log_level_t level, const char *file, int line, const char *fmt, ...) {
    time_t now;
    struct tm tm_now;
    char time_buf[20];
    va_list args;
    const char *level_str = "UNKNOWN";

    if (!log_file) return;

    switch (level) {
        case LOG_DEBUG: level_str = "DEBUG"; break;
        case LOG_INFO:  level_str = "INFO "; break;
        case LOG_WARN:  level_str = "WARN "; break;
        case LOG_ERROR: level_str = "ERROR"; break;
    }

    time(&now);
    localtime_r(&now, &tm_now);
    strftime(time_buf, sizeof(time_buf), "%Y-%m-%d %H:%M:%S", &tm_now);

    fprintf(log_file, "[%s] [%s] [%s:%d] ", time_buf, level_str, file, line);
    va_start(args, fmt);
    vfprintf(log_file, fmt, args);
    va_end(args);
    fprintf(log_file, "\n");
    fflush(log_file);
}

void logger_close(void) {
    if (log_file) {
        fclose(log_file);
        log_file = NULL;
    }
}

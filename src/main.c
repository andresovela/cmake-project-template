#define __FILENAME__     "main.c"
#define LOG_MODULE_GROUP LOG_GROUP_DEFAULT
#define LOG_LEVEL        LOG_LEVEL_DEBUG
#include "logging.h"

int main(int argc, char *argv[]) {
    log_info("Program running");
    return 0;
}
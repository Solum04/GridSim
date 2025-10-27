#include "logger.h"
#include <spdlog/sinks/stdout_color_sinks.h>

namespace {
std::shared_ptr<spdlog::logger> g_logger;
}

namespace gs {
void init_logger() {
    if (!g_logger) {
        g_logger = spdlog::stdout_color_mt("gridsim");
        spdlog::set_pattern("[%H:%M:%S.%e] [%^%l%$] %v");
        spdlog::set_level(spdlog::level::debug);
    }
}
std::shared_ptr<spdlog::logger> logger() {
    if (g_logger) return g_logger;
    return spdlog::default_logger();
}
}

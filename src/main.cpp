#include "core/logger.h"
#include "core/config.h"
#include <iostream>

int main() {
    gs::init_logger();
    try {
        auto cfg = gs::load_config("assets/config.json");
        gs::logger()->info("Config loaded. tick_rate={} grid_w={} grid_h={}",
                           cfg.value("tick_rate", 60),
                           cfg.value("grid_w", 20),
                           cfg.value("grid_h", 15));
    } catch (const std::exception& e) {
        gs::logger()->error("{}", e.what());
        return 1;
    }
    gs::logger()->info("GridSim M0 scaffold OK.");
    return 0;
}

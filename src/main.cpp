#include "core/logger.h"
#include "core/config.h"
#include "core/application.h"
#include "sims/isimulation.h"
#include "sims/dummy_sim.h"

int main() {
    gs::init_logger();
    try {
        auto cfg = gs::load_config("assets/config.json");

        const int tick_rate   = cfg.value("tick_rate", 60);
        const double seconds  = cfg.value("demo_seconds", 2.0); // legg til i config, se under

        gs::logger()->info("Starting Application: tick_rate={}Hz, demo_seconds={}", tick_rate, seconds);

        gs::Application app(tick_rate);
        gs::DummySim sim;

        app.run_for_seconds(seconds, sim);

        gs::logger()->info("Finished. updates={}, renders={}", sim.updates(), sim.renders());

    } catch (const std::exception& e) {
        gs::logger()->error("{}", e.what());
        return 1;
    }
    return 0;
}

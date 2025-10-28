//
// Created by krist on 28.10.2025.
//
#include "application.h"
#include "clock.h"
#include "logger.h"
#include "../sim/isimulation.h"

namespace gs {

Application::Application(int tick_rate)
    : m_tick_rate(tick_rate) {}

void Application::run_for_seconds(double seconds, ISimulation& sim) {
    const double target_dt = 1.0 / static_cast<double>(m_tick_rate);

    double start = now_seconds();
    double prev  = start;
    double acc   = 0.0;

    while (true) {
        double now  = now_seconds();
        double frame = now - prev;
        prev = now;
        acc += frame;

        // Fast-oppdatering (kan kjøre 0..N ganger per frame)
        while (acc >= target_dt) {
            sim.update(static_cast<float>(target_dt));
            acc -= target_dt;
        }

        // Render 1x per frame
        sim.render();

        // Stoppkriterium i M1
        if ((now - start) >= seconds) break;

        // kort pust så CPU ikke spinner helt
        sleep_ms(1);
    }

    logger()->info("Application finished run_for_seconds({}s) at {} Hz", seconds, m_tick_rate);
}

}
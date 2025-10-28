//
// Created by krist on 28.10.2025.
//
#include <catch2/catch_all.hpp>
#include "core/application.h"
#include "core/clock.h"
#include "core/logger.h"
#include "../src/sims/isimulation.h"

using namespace gs;

struct FakeSim : ISimulation {
    int updates = 0;
    int renders = 0;
    void update(float) override { updates++; }
    void render() override { renders++; }
};

TEST_CASE("Application runs approximately tick_rate * seconds updates") {
    init_logger();
    const int tick = 60;
    Application app(tick);
    FakeSim sim;

    // Kjør i ~0.5 sekund
    app.run_for_seconds(0.5, sim);

    // Forvent ca 30 updates (± litt timing-toleranse)
    REQUIRE(sim.updates >= 25);
    REQUIRE(sim.updates <= 40);

    // Render bør i det minste ha kjørt noen ganger
    REQUIRE(sim.renders > 0);
}


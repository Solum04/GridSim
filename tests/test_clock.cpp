//
// Created by krist on 28.10.2025.
//

#include <catch2/catch_all.hpp>
#include "core/clock.h"

TEST_CASE("now_seconds increases over time") {
    double t1 = gs::now_seconds();
    gs::sleep_ms(5);
    double t2 = gs::now_seconds();
    REQUIRE(t2 > t1);
}

TEST_CASE("sleep_ms waits at least the requested duration-ish") {
    double t1 = gs::now_seconds();
    gs::sleep_ms(10);
    double t2 = gs::now_seconds();
    // Windows-timer kan være litt grov: krev minst ~8ms
    REQUIRE( (t2 - t1) >= 0.008 );
}

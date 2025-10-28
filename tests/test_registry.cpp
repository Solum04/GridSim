//
// Created by krist on 28.10.2025.
//
#include <catch2/catch_all.hpp>
#include "ecs/registry.h"

using namespace gs;

TEST_CASE("registry create/destroy/alive works and recycles ids") {
    Registry r;
    Entity a = r.create();
    Entity b = r.create();
    Entity c = r.create();

    REQUIRE(a != kInvalidEntity);
    REQUIRE(b != kInvalidEntity);
    REQUIRE(c != kInvalidEntity);
    REQUIRE(r.alive(a));
    REQUIRE(r.alive(b));
    REQUIRE(r.alive(c));

    r.destroy(b);
    REQUIRE_FALSE(r.alive(b));

    // Neste create bør gjenbruke b sin id
    Entity d = r.create();
    REQUIRE(r.alive(d));
    REQUIRE(d == b); // resirkulert
}

//
// Created by krist on 28.10.2025.
//
#include <catch2/catch_all.hpp>
#include "ecs/component_pool.h"

struct Position { int x{}, y{}; };

TEST_CASE("ComponentPool basic has/get behavior") {
    gs::ComponentPool<Position> pool;
    gs::Entity e1 = 1, e2 = 42;

    // ingen komponenter enda
    REQUIRE_FALSE(pool.has(e1));
    REQUIRE(pool.get(e1) == nullptr);

    // kunstig legg til direkte (add() kommer senere)
    pool.ensure_sparse(e1);
    pool.ensure_sparse(e2);

    // verifiser at resizing ikke ødelegger noe
    REQUIRE_FALSE(pool.has(e1));
    REQUIRE_FALSE(pool.has(e2));
}

#include <catch2/catch_all.hpp>
#include "core/config.h"

TEST_CASE("load_config_reads_json") {
    auto j = gs::load_config("assets/config.json");
    REQUIRE(j.contains("tick_rate"));
    REQUIRE(j["tick_rate"].is_number());
}

#include <catch2/catch.hpp>

#include <grid/grid.h>

TEST_CASE("Grid can be constructed", "[grid]") {
    SECTION("Default constructable") {
        auto g = grid::Grid<int>{};
        REQUIRE(g.size() == 0);
        REQUIRE(g.empty() == true);
    }
    SECTION("Constructed to dimensions") {
        auto g = grid::Grid<int>{{5, 5}};
        REQUIRE(g.size() == 5 * 5);
        REQUIRE(g.empty() == false);
    }
}

TEST_CASE("Grid can be resized", "[grid]") {
    auto g = grid::Grid<int>{{5, 5}};
    REQUIRE(g.size() == 5 * 5);
    SECTION("After resize up, size has changed") {
        g.resize({10, 10});
        REQUIRE(g.size() == 10 * 10);
    }
    SECTION("After resize up, size has changed") {
        g.resize({3, 3});
        REQUIRE(g.size() == 3 * 3);
    }
    SECTION("After resize same, size is same") {
        g.resize({5, 5});
        REQUIRE(g.size() == 5 * 5);
    }
}

#include <catch2/catch_test_macros.hpp>
#include "ac/filesystem.hpp"

TEST_CASE ("Test File class.", "[single-file]") {
    ac::filesystem::File notouch("frame_notouch.bin");
    ac::filesystem::File touch("frame_touch.bin");
    REQUIRE(notouch.exists() == true);
    REQUIRE(touch.exists() == false);
    REQUIRE(notouch.suffix() == "bin");
    REQUIRE(notouch.stem() == "frame_notouch");
    REQUIRE(notouch.name() == "frame_notouch.bin");
}


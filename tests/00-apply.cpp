#include <catch2/catch_test_macros.hpp>

#include "ac/apply.hpp"

std::string append_int(std::string s, int i) {
    return s + std::to_string(i);
}

TEST_CASE ("Invoke the `append_int` with a tuple of arguments", "[single-file]") {
    auto s = ac::apply(append_int, std::make_tuple("hi ", 42));
    REQUIRE( s == "hi 42" );
}

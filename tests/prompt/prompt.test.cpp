#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "test/doctest.h"

int addition(int a, int b) {
    return a + b;
}

TEST_CASE("Addition test") {
    CHECK(addition(2, 3) == 5);
    CHECK(addition(-1, 1) == 0);
    CHECK(addition(0, 0) == 0);
}
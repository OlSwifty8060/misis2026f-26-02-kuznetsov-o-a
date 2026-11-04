#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>
#include <rational/rational.hpp>

TEST_CASE("Rational basic") {
  Rational r(1, 2);
  CHECK(r.num() == 1);
  CHECK(r.den() == 2);
}

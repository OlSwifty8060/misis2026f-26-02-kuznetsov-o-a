#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>
#include <rational/rational.hpp>

TEST_CASE("Rational default ctor") {
  Rational r;
  CHECK(r.num() == 0);
  CHECK(r.den() == 1);
}

TEST_CASE("Rational ctor and normalize") {
  Rational r1(3);
  CHECK(r1.num() == 3);
  CHECK(r1.den() == 1);

  Rational r2(-6, 2);
  CHECK(r2.num() == -3);
  CHECK(r2.den() == 1);

  Rational r3(2, -6);
  CHECK(r3.num() == -1);
  CHECK(r3.den() == 3);

  CHECK_THROWS(Rational(1, 0));
}

TEST_CASE("Rational arithmetic") {
  Rational a(1, 2);
  Rational b(1, 3);
  CHECK(a + b == Rational(5, 6));
  CHECK(a - b == Rational(1, 6));
  CHECK(a * b == Rational(1, 6));
  CHECK(a / b == Rational(3, 2));
}

TEST_CASE("Rational compare") {
  CHECK(Rational(1, 2) < Rational(2, 3));
  CHECK(Rational(1, 2) == Rational(2, 4));
  CHECK(Rational(3, 4) > Rational(1, 2));
}

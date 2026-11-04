#include <rational/rational.hpp>
#include <stdexcept>

Rational::Rational(const std::int32_t num) noexcept : num_(num), den_(1) {}

Rational::Rational(const std::int32_t num, const std::int32_t den)
  : num_(num), den_(den) {
  if (den_ == 0) {
    throw std::invalid_argument("Zero denominator in Rational ctor");
  }
  normalize();
}

void Rational::normalize() noexcept {}

bool Rational::operator==(const Rational&) const noexcept { return true; }
bool Rational::operator!=(const Rational&) const noexcept { return true; }
bool Rational::operator<(const Rational&) const noexcept { return true; }
bool Rational::operator<=(const Rational&) const noexcept { return true; }
bool Rational::operator>(const Rational&) const noexcept { return true; }
bool Rational::operator>=(const Rational&) const noexcept { return true; }

Rational Rational::operator-() const noexcept { return Rational(-num_, den_); }

Rational& Rational::operator+=(const Rational&) noexcept { return *this; }
Rational& Rational::operator-=(const Rational&) noexcept { return *this; }
Rational& Rational::operator*=(const Rational&) noexcept { return *this; }
Rational& Rational::operator/=(const Rational&) { return *this; }

Rational& Rational::operator+=(const std::int32_t rhs) noexcept { return operator+=(Rational(rhs)); }
Rational& Rational::operator-=(const std::int32_t rhs) noexcept { return operator-=(Rational(rhs)); }
Rational& Rational::operator*=(const std::int32_t rhs) noexcept { return operator*=(Rational(rhs)); }
Rational& Rational::operator/=(const std::int32_t rhs) { return operator/=(Rational(rhs)); }

std::ostream& Rational::write_to(std::ostream& ostrm) const noexcept { return ostrm; }
std::istream& Rational::read_from(std::istream& istrm) noexcept { return istrm; }

Rational operator+(const Rational& lhs, const Rational& rhs) noexcept { return Rational(lhs) += rhs; }
Rational operator-(const Rational& lhs, const Rational& rhs) noexcept { return Rational(lhs) -= rhs; }
Rational operator*(const Rational& lhs, const Rational& rhs) noexcept { return Rational(lhs) *= rhs; }
Rational operator/(const Rational& lhs, const Rational& rhs) { return Rational(lhs) /= rhs; }

std::ostream& operator<<(std::ostream& ostrm, const Rational& rhs) noexcept { return rhs.write_to(ostrm); }
std::istream& operator>>(std::istream& istrm, Rational& rhs) noexcept { return rhs.read_from(istrm); }

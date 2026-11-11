#include <rational/rational.hpp>

#include <iostream>
#include <stdexcept>

namespace {
  // свой gcd, без std::gcd (требование недели 10)
  std::int32_t gcd(std::int32_t a, std::int32_t b) noexcept {
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    while (b != 0) {
      const std::int32_t t = a % b;
      a = b;
      b = t;
    }
    return a;
  }
}

Rational::Rational(const std::int32_t num) noexcept : num_(num), den_(1) {}

Rational::Rational(const std::int32_t num, const std::int32_t den)
  : num_(num), den_(den) {
  if (0 == den_) {
    throw std::invalid_argument("Rational: zero denominator");
  }
  normalize();
}

void Rational::normalize() noexcept {
  if (den_ < 0) {
    num_ = -num_;
    den_ = -den_;
  }
  const std::int32_t g = gcd(num_, den_);
  if (g > 1) {
    num_ /= g;
    den_ /= g;
  }
}

bool Rational::operator==(const Rational& rhs) const noexcept {
  return num_ == rhs.num_ && den_ == rhs.den_;
}
bool Rational::operator!=(const Rational& rhs) const noexcept {
  return !(*this == rhs);
}
bool Rational::operator<(const Rational& rhs) const noexcept {
  return static_cast<std::int64_t>(num_) * rhs.den_
       < static_cast<std::int64_t>(rhs.num_) * den_;
}
bool Rational::operator<=(const Rational& rhs) const noexcept {
  return !(*this > rhs);
}
bool Rational::operator>(const Rational& rhs) const noexcept {
  return rhs < *this;
}
bool Rational::operator>=(const Rational& rhs) const noexcept {
  return !(*this < rhs);
}

Rational Rational::operator-() const noexcept {
  return Rational(-num_, den_);
}

Rational& Rational::operator+=(const Rational& rhs) noexcept {
  num_ = num_ * rhs.den_ + rhs.num_ * den_;
  den_ = den_ * rhs.den_;
  normalize();
  return *this;
}
Rational& Rational::operator-=(const Rational& rhs) noexcept {
  num_ = num_ * rhs.den_ - rhs.num_ * den_;
  den_ = den_ * rhs.den_;
  normalize();
  return *this;
}
Rational& Rational::operator*=(const Rational& rhs) noexcept {
  num_ *= rhs.num_;
  den_ *= rhs.den_;
  normalize();
  return *this;
}
Rational& Rational::operator/=(const Rational& rhs) {
  if (0 == rhs.num_) {
    throw std::invalid_argument("Rational: division by zero");
  }
  num_ *= rhs.den_;
  den_ *= rhs.num_;
  normalize();
  return *this;
}

Rational& Rational::operator+=(const std::int32_t rhs) noexcept {
  return *this += Rational(rhs);
}
Rational& Rational::operator-=(const std::int32_t rhs) noexcept {
  return *this -= Rational(rhs);
}
Rational& Rational::operator*=(const std::int32_t rhs) noexcept {
  return *this *= Rational(rhs);
}
Rational& Rational::operator/=(const std::int32_t rhs) {
  return *this /= Rational(rhs);
}

std::ostream& Rational::write_to(std::ostream& ostrm) const noexcept {
  ostrm << num_ << '/' << den_;
  return ostrm;
}

std::istream& Rational::read_from(std::istream& istrm) noexcept {
  std::int32_t num = 0;
  char slash = 0;
  std::int32_t den = 0;
  istrm >> num >> slash >> den;
  if (istrm.good()) {
    if (slash == '/' && den != 0) {
      num_ = num;
      den_ = den;
      normalize();
    } else {
      istrm.setstate(std::ios_base::failbit);
    }
  }
  return istrm;
}

Rational operator+(const Rational& lhs, const Rational& rhs) noexcept {
  return Rational(lhs) += rhs;
}
Rational operator-(const Rational& lhs, const Rational& rhs) noexcept {
  return Rational(lhs) -= rhs;
}
Rational operator*(const Rational& lhs, const Rational& rhs) noexcept {
  return Rational(lhs) *= rhs;
}
Rational operator/(const Rational& lhs, const Rational& rhs) {
  return Rational(lhs) /= rhs;
}

Rational operator+(const Rational& lhs, const std::int32_t rhs) noexcept {
  return Rational(lhs) += rhs;
}
Rational operator-(const Rational& lhs, const std::int32_t rhs) noexcept {
  return Rational(lhs) -= rhs;
}
Rational operator*(const Rational& lhs, const std::int32_t rhs) noexcept {
  return Rational(lhs) *= rhs;
}
Rational operator/(const Rational& lhs, const std::int32_t rhs) {
  return Rational(lhs) /= rhs;
}

Rational operator+(const std::int32_t lhs, const Rational& rhs) noexcept {
  return Rational(lhs) += rhs;
}
Rational operator-(const std::int32_t lhs, const Rational& rhs) noexcept {
  return Rational(lhs) -= rhs;
}
Rational operator*(const std::int32_t lhs, const Rational& rhs) noexcept {
  return Rational(lhs) *= rhs;
}
Rational operator/(const std::int32_t lhs, const Rational& rhs) {
  return Rational(lhs) /= rhs;
}

std::ostream& operator<<(std::ostream& ostrm, const Rational& rhs) noexcept {
  return rhs.write_to(ostrm);
}
std::istream& operator>>(std::istream& istrm, Rational& rhs) noexcept {
  return rhs.read_from(istrm);
}
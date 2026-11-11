#include <complex/complex.hpp>

#include <cmath>
#include <limits>
#include <stdexcept>

namespace {
  constexpr double eps = 2.0 * std::numeric_limits<double>::epsilon();
}

Complex::Complex(const double real) : re(real), im(0.0) {}

Complex::Complex(const double real, const double imaginary)
  : re(real), im(imaginary) {}

Complex Complex::operator-() const noexcept {
  return Complex(-re, -im);
}

bool Complex::operator==(const Complex& rhs) const noexcept {
  return std::abs(re - rhs.re) <= eps && std::abs(im - rhs.im) <= eps;
}

bool Complex::operator!=(const Complex& rhs) const noexcept {
  return !(*this == rhs);
}

Complex& Complex::operator+=(const Complex& rhs) noexcept {
  re += rhs.re;
  im += rhs.im;
  return *this;
}

Complex& Complex::operator+=(const double rhs) noexcept {
  re += rhs;
  return *this;
}

Complex& Complex::operator-=(const Complex& rhs) noexcept {
  re -= rhs.re;
  im -= rhs.im;
  return *this;
}

Complex& Complex::operator-=(const double rhs) noexcept {
  re -= rhs;
  return *this;
}

Complex& Complex::operator*=(const Complex& rhs) noexcept {
  const double new_re = re * rhs.re - im * rhs.im;
  const double new_im = re * rhs.im + im * rhs.re;
  re = new_re;
  im = new_im;
  return *this;
}

Complex& Complex::operator*=(const double rhs) noexcept {
  re *= rhs;
  im *= rhs;
  return *this;
}

Complex& Complex::operator/=(const Complex& rhs) {
  const double denom = rhs.re * rhs.re + rhs.im * rhs.im;
  if (std::abs(denom) <= eps) {
    throw std::invalid_argument("Complex: division by zero");
  }
  const double new_re = (re * rhs.re + im * rhs.im) / denom;
  const double new_im = (im * rhs.re - re * rhs.im) / denom;
  re = new_re;
  im = new_im;
  return *this;
}

Complex& Complex::operator/=(const double rhs) {
  if (std::abs(rhs) <= eps) {
    throw std::invalid_argument("Complex: division by zero");
  }
  re /= rhs;
  im /= rhs;
  return *this;
}

std::ostream& Complex::write_to(std::ostream& ostrm) const noexcept {
  ostrm << leftBrace << re << separator << im << rightBrace;
  return ostrm;
}

std::istream& Complex::read_from(std::istream& istrm) noexcept {
  char left = 0;
  double real = 0.0;
  char sep = 0;
  double imag = 0.0;
  char right = 0;

  istrm >> left >> real >> sep >> imag >> right;

  if (istrm.good()) {
    if (left == leftBrace && sep == separator && right == rightBrace) {
      re = real;
      im = imag;
    } else {
      istrm.setstate(std::ios_base::failbit);
    }
  }
  return istrm;
}

Complex operator+(const Complex& lhs, const Complex& rhs) noexcept {
  return Complex(lhs) += rhs;
}
Complex operator+(const Complex& lhs, const double rhs) noexcept {
  return Complex(lhs) += rhs;
}
Complex operator+(const double lhs, const Complex& rhs) noexcept {
  return Complex(lhs) += rhs;
}

Complex operator-(const Complex& lhs, const Complex& rhs) noexcept {
  return Complex(lhs) -= rhs;
}
Complex operator-(const Complex& lhs, const double rhs) noexcept {
  return Complex(lhs) -= rhs;
}
Complex operator-(const double lhs, const Complex& rhs) noexcept {
  return Complex(lhs) -= rhs;
}

Complex operator*(const Complex& lhs, const Complex& rhs) noexcept {
  return Complex(lhs) *= rhs;
}
Complex operator*(const Complex& lhs, const double rhs) noexcept {
  return Complex(lhs) *= rhs;
}
Complex operator*(const double lhs, const Complex& rhs) noexcept {
  return Complex(lhs) *= rhs;
}

Complex operator/(const Complex& lhs, const Complex& rhs) {
  return Complex(lhs) /= rhs;
}
Complex operator/(const Complex& lhs, const double rhs) {
  return Complex(lhs) /= rhs;
}
Complex operator/(const double lhs, const Complex& rhs) {
  return Complex(lhs) /= rhs;
}

#include <complex/complex.hpp>

#include <iostream>
#include <sstream>
#include <stdexcept>

int main() {
  Complex a(1.0, 2.0);
  Complex b(3.0, -4.0);

  std::cout << "a = " << a << "\n";
  std::cout << "b = " << b << "\n";
  std::cout << "a + b = " << (a + b) << "\n";
  std::cout << "a - b = " << (a - b) << "\n";
  std::cout << "a * b = " << (a * b) << "\n";
  std::cout << "a / b = " << (a / b) << "\n";
  std::cout << "-a = " << (-a) << "\n";

  // проверка ввода/вывода
  std::istringstream input("{2.5,-1.5}");
  Complex c;
  input >> c;
  std::cout << "read c = " << c << "\n";

  // деление на ноль
  try {
    Complex z = a / 0.0;
    std::cout << "no exception (bad)\n";
  } catch (const std::invalid_argument& ex) {
    std::cout << "caught: " << ex.what() << "\n";
  }

  // сравнение
  Complex d(1.0, 2.0);
  std::cout << "a == d ? " << (a == d) << "\n";
  std::cout << "a != b ? " << (a != b) << "\n";

  return 0;
}
#include "src/Fraction/Fraction.hpp"
int main()
{
  try {
      Fraction a(1, 2);
      Fraction b(1, 3);

      std::cout << "a = " << a << std::endl;
      std::cout << "b = " << b << std::endl;

      Fraction c = a + b;
      std::cout << "a + b = " << c << std::endl;

      Fraction d = a * b;
      std::cout << "a * b = " << d << std::endl;

      Fraction e = a / b;
      std::cout << "a / b = " << e << std::endl;

      std::cout << "Is a == b? " << (a == b) << std::endl;
      std::cout << "Is a != b? " << (a != b) << std::endl;
      std::cout << "Is a < b? " << (a < b) << std::endl;
      std::cout << "Is a > b? " << (a > b) << std::endl;

      Fraction f = ++a;
      std::cout << "++a = " << f << std::endl;

      Fraction g = --b;
      std::cout << "--b = " << g << std::endl;

      Fraction h = -a;
      std::cout << "-a = " << h << std::endl;

      Fraction i = !a;
      std::cout << "Inverse of a: " << i << std::endl;

      std::cout << "Enter a fraction (numerator/denominator): ";
      Fraction j;
      std::cin >> j;
      std::cout << "You entered: " << j << std::endl;

      std::cout << "Fraction a as double: " << static_cast<double>(a) << std::endl;

      Fraction k;
      k = b;
      std::cout << "k = b: " << k << std::endl;

      a += b;
      std::cout << "a += b: " << a << std::endl;

      b -= a;
      std::cout << "b -= a: " << b << std::endl;

      c *= a;
      std::cout << "c *= a: " << c << std::endl;

      e /= b;
      std::cout << "e /= b: " << e << std::endl;
  }
  catch (const Exception& ex) {
      std::cerr << "Exception: " << ex.getMessage() << std::endl;
  }
  return 0;
}

#include "whatever.hpp"
#include <iostream>
#include <string>

int main()
{
  std::cout << "show me min(4, 3) : " << min<int>(4, 3) << std::endl;
  std::cout << "show me max(a, e) : " << max<char>('a', 'e') << std::endl;
  std::cout << "show me min(bob, alice) : " << min<std::string>("Bob", "Alice") << std::endl;
  char a = 'a', b = 'b';
  int x = 4, y = 7;
  std::cout << "currently, (a, b) = " << a << ", " << b << " and (x, y) = " << x << ", " << y << std::endl;
  swap<char>(a, b);
  swap<int>(x, y);
  std::cout << "after swap, (a, b) = " << a << ", " << b << " and (x, y) = " << x << ", " << y << std::endl;
}

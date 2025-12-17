#include "iter.hpp"
#include <string>

void add_two(int &s)
{
  s += 2;
}

int main()
{
  std::string Array[] = {"here", "a", "few", "words", "over", "here"};
  int x[] = {5,4,47,52,1};
  char y[] = {'g','t','h','e','n'};
  iter<int>(x, 5, &printer);
  std::cout << std::endl;
  iter<int>(x, 5, &add_two);
  iter<int>(x, 5, &printer);
  std::cout << "\nand then strings and chars\n\n";
  iter<std::string>(Array, 6, &printer);
  std::cout << std::endl;
  iter<char>(y, 5, &printer);
}

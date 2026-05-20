#include <iostream>

int main(int argc, char **argv)
{
  std::cout << "Hello World ! I really hope this works out for you, dove. See you later, ";
  if (argc > 1) { std::cout << argv[1] << std::endl; }
  else { std::cout << "no argument\n"; }
  return 0;
}

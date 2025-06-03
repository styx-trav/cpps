#include <cstring>
#include <iostream>

int main()
{
  std::string myString = "HI THIS IS BRAIN";
  std::string *stringPTR = &myString;
  std::string &stringREF = myString;
  
  std::cout << "here the address of myString : " << &myString << ", the address kept in stringPTR : " << stringPTR << ", and the address of stringREF : " << &stringREF << "\n";
  std::cout << "and now here the value of myString : " << myString << ", the value at the address of stringPTR : " << *stringPTR << ", and the value of stringREF : " << stringREF << "\n";
}

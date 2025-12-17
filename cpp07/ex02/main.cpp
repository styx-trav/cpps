#include "Array.hpp"

int main()
{
  {
    Array<int> obj(3);
    std::cout << std::endl;
    std::cout << "size of array : " << obj.size() << std::endl;
    std::cout << std::endl;
    try
    {
      obj[0] = 7;
      obj[1] = 8;
      obj[2] = 2;
      obj[3] = 78;
    }
    catch (std::exception &e)
    {
      std::cout << "you are out of bounds !\n\n";
    }
    obj.print();
    std::cout << std::endl;
  }
  {
    std::cout << std::endl;
    Array<std::string> obj(2);
    std::cout << std::endl;
    std::cout << "size of array : " << obj.size() << std::endl;
    std::cout << std::endl;
    try
    {
      obj[0] = "a string ? no way !";
      obj[1] = "and another, too !";
      obj[2] = "yeah, afraid this one won't make it.";
    }
    catch (std::exception &e)
    {
      std::cout << "you are out of bounds !\n\n";
    }
    Array<std::string> obj2(obj);
    std::cout << std::endl;
    Array<std::string> obj3;
    obj3 = obj;
    std::cout << std::endl;
    try
    {
      obj2[0] = "oooh, a different string !";
      obj3[1] = "and a little switch-up here at the end";
    }
    catch (std::exception &e)
    {
      std::cout << "you are out of bounds !\n\n";
    }
    obj.print();
    std::cout << std::endl;
    obj2.print();
    std::cout << std::endl;
    obj3.print();
    std::cout << std::endl;
  }
  {
    std::cout << std::endl;
    Array<char> obj;
    std::cout << std::endl;
    std::cout << "size of array : " << obj.size() << std::endl;
    std::cout << std::endl;
    try
    {
      obj[0] = 'a';
      obj[1] = 's';
    }
    catch (std::exception &e)
    {
      std::cout << "you are out of bounds !\n\n";
    }
    obj.print();
    std::cout << std::endl;
  }
}

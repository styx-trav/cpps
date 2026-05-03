#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <deque>
#include <list>

int main()
{
  {
    std::vector<int> obj(6, 5);
    obj.at(1) = 7;
    obj.at(2) = 4;
    obj.at(3) = 6;
    obj.at(5) = 4;
    //{5, 7, 4, 6, 5, 4};
    //finding 4;
    std::cout << "looking for \"4\" in vector {5 7 4 6 5 4} : ";
    try
    {
      if (&(easyfind<std::vector<int> >(obj, 4)) == &(obj.at(2)))
        std::cout << "found it !\n";
      else
        std::cout << "wrong reference returned !\n";
    }
    catch (std::exception &e)
    {
      std::cout << "couldn't find that\n";
    }
    const std::vector<int> obj_cpy(obj);
    //{5, 7, 4, 6, 5, 4};
    //finding 4;
    std::cout << "looking for \"4\" in vector copy {5 7 4 6 5 4} : ";
    try
    {
      if (&(easyfind<std::vector<int> >(obj_cpy, 4)) == &(obj_cpy.at(2)))
        std::cout << "found it !\n";
      else
        std::cout << "wrong reference returned !\n";
    }
    catch (std::exception &e)
    {
      std::cout << "couldn't find that\n";
    }
  }
  {
    std::deque<int> obj;
    obj.push_back(5);
    obj.push_back(6);
    obj.push_back(4);
    obj.push_back(6);
    obj.push_back(6);
    //{5, 6, 4, 6, 6};
    //finding 7;
    std::cout << "looking for \"7\" in deque {5 6 4 6 6} : ";
    try
    {
      std::cout << easyfind<std::deque<int> >(obj, 7) << "returned !\n";
    }
    catch (std::exception &e)
    {
      std::cout << "couldn't find that\n";
    }
  }
  {
    std::list<int> obj;
    std::cout << "looking for \"5\" in empty list {} : ";
    try
    {
        std::cout << easyfind<std::list<int> >(obj, 5) << "returned\n";
    }
    catch (std::exception &e)
    {
      std::cout << "couldn't find that\n";
    }
    obj.push_back(5);
    obj.push_back(6);
    obj.push_back(4);
    obj.push_back(5);
    obj.push_back(7);
    //{5, 6, 4, 5, 7};
    //finding 5;
    std::cout << "looking for \"5\" in list {5 6 4 6 5 7} : ";
    try
    {
      if (&(easyfind<std::list<int> >(obj, 5)) == &(obj.front()))
        std::cout << "found it !\n";
      else
        std::cout << "wrong reference returned !\n";
    }
    catch (std::exception &e)
    {
      std::cout << "couldn't find that\n";
    }
  }
}

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
    try
    {
      if (&(easyfind<std::vector<int> >(obj, 11)) == &(obj.at(2)))
        std::cout << "found it !\n";
      else
        std::cout << "something went wrong !\n";
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
    obj.push_back(7);
    //{5, 6, 4, 6, 7};
    //finding 7;
    try
    {
      if (&(easyfind<std::deque<int> >(obj, 7)) == &(obj.back()))
        std::cout << "found it !\n";
      else
        std::cout << "something went wrong !\n";
    }
    catch (std::exception &e)
    {
      std::cout << "couldn't find that\n";
    }
  }
  {
    std::list<int> obj;
    obj.push_back(5);
    obj.push_back(6);
    obj.push_back(4);
    obj.push_back(6);
    obj.push_back(7);
    //{5, 6, 4, 6, 7};
    //finding 5;
    try
    {
      if (&(easyfind<std::list<int> >(obj, 17)) == &(obj.front()))
        std::cout << "found it !\n";
      else
        std::cout << "something went wrong !\n";
    }
    catch (std::exception &e)
    {
      std::cout << "couldn't find that\n";
    }
  }
}

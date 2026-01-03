#include "MutantStack.hpp"
#include <cstring>

int main()
{
  MutantStack<int> letsee;
  letsee.push(7);
  letsee.push(5);
  letsee.push(4);
  letsee.push(5);
  letsee.push(6);
  letsee.push(0);
  letsee.print();
  std::cout << std::endl;
  
  const MutantStack<int> letsee2(letsee);
  letsee2.print();
  MutantStack<int>::const_iterator it = letsee2.begin();
  MutantStack<int>::const_reverse_iterator rit = letsee2.rbegin();
  it++;
  it++;
  rit++;
  //*rit += 7;
  std::cout << "and the third :: " << *it << " and one to last :: " << *rit << std::endl << std::endl;
  
  std::vector<std::string> cont;
  cont.push_back("here");
  cont.push_back("some");
  cont.push_back("more");
  cont.push_back("words");
  MutantStack<std::string, std::vector<std::string> > letsee3(cont);
  letsee3.print();
  MutantStack<std::string, std::vector<std::string> >::reverse_iterator ritt = letsee3.rbegin();
  ritt++;
  *ritt += " and more";
  std::cout << "and one to last :: " << *ritt << std::endl << std::endl;
}

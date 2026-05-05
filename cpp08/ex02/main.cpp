#include "MutantStack.hpp"
#include <cstring>

int main()
{
	{
		MutantStack<int> letsee;
		letsee.push(7);
		letsee.push(5);
		letsee.push(4);
		letsee.push(5);
		letsee.push(6);
		letsee.push(0);
		std::cout << "see stack of size " << letsee.size() << ", is not empty : " << letsee.empty() << " ; " << std::endl;
		letsee.print();
		std::cout << "lets pop twice (delete 0, 6)" << std::endl;
		letsee.pop();
		letsee.pop();
		letsee.print();
  
		const MutantStack<int> letsee2(letsee);
		letsee2.print();
		MutantStack<int>::const_iterator it = letsee2.begin();
		MutantStack<int>::const_reverse_iterator rit = letsee2.rbegin();
		it++;
		it++;
		rit++;
		std::cout << "and the third :: " << *it << " and one to last :: " << *rit << ", and current top " << letsee2.top() << std::endl << std::endl;
	}
	{
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
		std::cout << "and new one to last :: " << *ritt << std::endl << std::endl;
	}
	{
		std::cout << "\nnow testing : stack v list\n";
		MutantStack<std::string> obj;
		std::list<std::string> obj1;
		std::cout << "both containers are currently empty :: " << obj.empty() << ", " << obj1.empty() << std::endl;
		obj.push("first string");
		obj1.push_back("first string");
		obj.push("second string");
		obj1.push_back("second string");
		std::cout << "now both containers have size :: " << obj.size() << ", " << obj1.size() << std::endl;
		std::cout << "lets print them both :: \n";
		for (MutantStack<std::string>::const_iterator it = obj.begin(); it != obj.end(); it++) { std::cout << *it << ", "; }
		std::cout << std::endl;
		for (std::list<std::string>::const_iterator it = obj1.begin(); it != obj1.end(); it++) { std::cout << *it << ", "; }
		std::cout << std::endl;
		std::cout << "see their top/back : " << obj.top() << ", " << obj1.back() << std::endl;
		obj.pop();
		obj1.pop_back();
		std::cout << "see their new top/back : " << obj.top() << ", " << obj1.back() << std::endl;
	}
}

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <bits/stdc++.h>
# include <vector>
# include <deque>
# include <list>

template <class T, class Container = std::deque<T> > class MutantStack
{
  private:
    T arr;
  public:
    MutantStack() {std::cout << "creating MutantStack\n";};
    ~MutantStack(){std::cout << "destroying MutantStack\n";};
    MutantStack(MutantStack &other){arr = other.arr; std::cout << "creating (copy) MutantStack\n";};
    MutantStack &operator=(MutantStack &other)
    {
      if (this != &other)
      {
        arr = other.arr;
        std::cout << "MutantStack copy assignment called\n";
      }
      return *this;
    };
    unsigned int size() const {return arr.size();};
    bool empty() const {return arr.empty();};
    void push(T &item) {arr.push_back(item);};
    void pop() {arr.pop_back();};
    T &top() {return arr.back();};
}

#endif

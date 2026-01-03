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
    Container arr;
  public:
    //constructors/destructor
    MutantStack() {std::cout << "creating MutantStack\n";};
    ~MutantStack(){std::cout << "destroying MutantStack\n";};
    MutantStack(const Container &other) : arr(other) {std::cout << "creating (from container) MutantStack\n";};
    MutantStack(MutantStack &other) : arr(other.arr){std::cout << "creating (copy) MutantStack\n";};
    MutantStack &operator=(MutantStack &other)
    {
      if (this != &other)
      {
        arr = other.arr;
        std::cout << "MutantStack copy assignment called\n";
      }
      return *this;
    };
    
    //iterators
    typedef typename Container::iterator iterator;
    typedef typename Container::reverse_iterator reverse_iterator;
    //iterator init
    inline iterator begin() {return arr.begin();};
    inline reverse_iterator rbegin() {return arr.rbegin();};
    inline iterator end() {return arr.end();};
    inline reverse_iterator rend() {return arr.rend();};
    
    //const iterators
    typedef typename Container::const_iterator const_iterator;
    typedef typename Container::const_reverse_iterator const_reverse_iterator;
    //const iterator init
    inline const_iterator begin() const {return arr.begin();};
    inline const_reverse_iterator rbegin() const {return arr.rbegin();};
    inline const_iterator end() const {return arr.end();};
    inline const_reverse_iterator rend() const {return arr.rend();};
    
    //stack-spec functions
    inline unsigned int size() const {return arr.size();};
    inline bool empty() const {return arr.empty();};
    inline void push(T item) {arr.push_back(item);};
    inline void pop() {arr.pop_back();};
    inline T &top() {return arr.back();};
    
    //added prints
    void print() {for (typename Container::iterator it = arr.begin(); it != arr.end(); it++) {std::cout << *it << ". ";} std::cout << std::endl;};
    void print() const {for (typename Container::const_iterator it = arr.begin(); it != arr.end(); it++) {std::cout << *it << ". ";} std::cout << std::endl;};
};

#endif

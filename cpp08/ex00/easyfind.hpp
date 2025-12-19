#ifndef EASYFIND_HPP
# define EASYFIND_HPP
# include <bits/stdc++.h>

template <typename T> int &easyfind(T &l, int num)
{
  for (typename T::iterator it = l.begin(); it != l.end(); it++)
  {
    if (*it == num)
      return *it;
  }
  throw std::exception();
}

#endif

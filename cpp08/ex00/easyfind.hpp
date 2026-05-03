#ifndef EASYFIND_HPP
# define EASYFIND_HPP
# include <bits/stdc++.h>

template <typename T> int &easyfind(T &l, const int num)
{
  for (typename T::iterator it = l.begin(); it != l.end(); it++)
  {
    if (*it == num)
      return *it;
  }
  throw std::exception();
}

template <typename T> const int &easyfind(const T &l, const int num)
{
  for (typename T::const_iterator it = l.begin(); it != l.end(); it++)
  {
    if (*it == num)
      return *it;
  }
  throw std::exception();
}

#endif

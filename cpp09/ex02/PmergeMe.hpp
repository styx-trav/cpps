#ifndef PMERGEME_HPP
# define PMERGEME_HPP
# include <vector>
# include <deque>
# include <iostream>
# include <cstring>
# include <sstream>
# include <cmath>
# include <time.h>

void do_all(int argc, char **argv);

template <class T> void print_list(T &ref)
{
	for (template T::iterator it = T.begin(); it != T.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

	//vector typedefs
typedef std::vector<unsigned int> a_vec;
typedef std::vector<std::pair<a_vec , a_vec> > s_vec;
//clock here
//setup ::
void setup(int argc, char **argv, a_vec &ref);
//full algorithm, in order ::
s_vec phase_one(a_vec &l, std::vector<a_vec> &lo); //very first pass, with a_vec nerf
s_vec phase_one(s_vec l, std::vector<a_vec> &lo); //every subsequent pass, with previous s_vec
s_vec phase_two(s_vec l, std::vector<a_vec> &lo); //phase two, starting with the last huge pair
//phase two utils
unsigned int get_a_pos(s_vec &res, unsigned int max); //slight optimisation on the "seeking a_pos"
bool cmp(unsigned int b, unsigned int a); //comparison + add to comps
void binary_insert(s_vec &res, a_vec &lo, unsigned int end); //binary insert algo portion
void makePair(s_vec &to_add, a_vec &add); //adding new pair at the end of the list
void makePair(s_vec &to_add, a_vec &add, unsigned int index); //adding new pair before index
//final round for a_vec return
void get_res(s_vec &res, a_vec &nerf);
//clock here

	//deque typedefs
typedef std::deque<unsigned int> a_deq;
typedef std::deque<std::pair<a_deq , a_deq> > s_deq;
//clock here
//setup ::
void setup(int argc, char **argv, a_deq &ref);
//full algorithm, in order ::
s_vec phase_one(a_deq &l, std::deque<a_deq> &lo); //very first pass, with a_deq nerf
s_vec phase_one(a_deq l, std::deque<a_deq> &lo); //every subsequent pass, with previous s_deq
s_vec phase_two(s_deq l, std::deque<a_deq> &lo); //phase two, starting with the last huge pair
//phase two utils
unsigned int get_a_pos(s_deq &res, unsigned int max); //slight optimisation on the "seeking a_pos"
void binary_insert(s_deq &res, a_deq &lo, unsigned int end); //binary insert algo portion
void makePair(s_deq &to_add, a_deq &add); //adding new pair at the end of the list
void makePair(s_deq &to_add, a_deq &add, unsigned int index); //adding new pair before index
//final round for a_deq return
void get_res(s_deq &res, a_deq &nerf);
//clock here

#endif

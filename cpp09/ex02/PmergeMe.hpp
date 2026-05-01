#ifndef PMERGEME_HPP
# define PMERGEME_HPP
# include <vector>
# include <deque>
# include <iostream>
# include <cstring>
# include <sstream>
# include <cmath>
# include <time.h>

//vector typedefs
typedef std::vector<unsigned int> a_vec;
typedef std::vector<std::pair<a_vec , a_vec> > s_vec;

//deque typedefs
typedef std::deque<unsigned int> a_deq;
typedef std::deque<std::pair<a_deq , a_deq> > s_deq;

void comps_add();

void do_all(int argc, char **argv);

//utils.cpp
bool cmp(unsigned int b, unsigned int a); //comparison + add to comps
int F(int n); //max amount of comps expected
unsigned int get_js(unsigned int n); //equation, approximated
void print_list(a_vec &ref); //print vectors (initial, end)

	//vector version
//clock here
//setup ::
void setup(int argc, char **argv, a_vec &ref);
//full algorithm, in order ::
s_vec phase_one(a_vec &l, std::vector<a_vec> &lo); //very first pass, with a_vec nerf
s_vec phase_one(s_vec l, std::vector<a_vec> &lo); //every subsequent pass, with previous s_vec
s_vec phase_two(s_vec l, std::vector<a_vec> &lo); //phase two, starting with the last huge pair
//phase two utils
unsigned int get_a_pos(s_vec &res, unsigned int max); //slight optimisation on the "seeking a_pos"
void binary_insert(s_vec &res, a_vec &lo, unsigned int end); //binary insert algo portion
void makePair(s_vec &to_add, a_vec &add); //adding new pair at the end of the list
void makePair(s_vec &to_add, a_vec &add, unsigned int index); //adding new pair before index
//final round for a_vec return
void get_res(s_vec &res, a_vec &nerf);
//clock here

	//deque version
//clock here
//setup ::
void setup_deq(int argc, char **argv, a_deq &ref);
//full algorithm, in order ::
s_deq phase_one_deq(a_deq &l, std::deque<a_deq> &lo); //very first pass, with a_deq nerf
s_deq phase_one_deq(s_deq l, std::deque<a_deq> &lo); //every subsequent pass, with previous s_deq
s_deq phase_two_deq(s_deq l, std::deque<a_deq> &lo); //phase two, starting with the last huge pair
//phase two utils
unsigned int get_a_pos_deq(s_deq &res, unsigned int max); //slight optimisation on the "seeking a_pos"
void binary_insert_deq(s_deq &res, a_deq &lo, unsigned int end); //binary insert algo portion
void makePair_deq(s_deq &to_add, a_deq &add); //adding new pair at the end of the list
void makePair_deq(s_deq &to_add, a_deq &add, unsigned int index); //adding new pair before index
//final round for a_deq return
void get_res_deq(s_deq &res, a_deq &nerf);
//clock here

#endif

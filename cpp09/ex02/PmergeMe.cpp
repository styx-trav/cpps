#include "PmergeMe.hpp"

int comps = 0;

void comps_add() { comps++; }

void do_all(int argc, char **argv)
{
	{
		a_vec list;
		s_vec res;
		std::vector<a_vec> leftovers;
		a_vec result;
		try { setup(argc, argv, list); }
		catch (std::exception &e) {return ; }
		clock_t start = clock();
		res = phase_one(list, leftovers);
		res = phase_two(res, leftovers);
		get_res(res, result);
		clock_t end = clock();
		std::cout << "Before : ";
		print_list(list);
		std::cout << "After : ";
		print_list(result);
		std::cout << "Time to process a sequence of " << list.size() << "numbers (vectors) : ";
		std::cout << (end - start) << std::endl;
		if (int diff = (F(list.size()) - comps) < 0)
			std::cout << "with " << diff << " discrepancy\n";
	}
	{
		comps = 0;
		a_deq list;
		s_deq res;
		std::deque<a_deq> leftovers;
		a_deq result;
		try { setup_deq(argc, argv, list); }
		catch (std::exception &e) {return ; }
		clock_t start = clock();
		res = phase_one_deq(list, leftovers);
		res = phase_two_deq(res, leftovers);
		get_res_deq(res, result);
		clock_t end = clock();
		std::cout << "Time to process a sequence of " << list.size() << "numbers (deques) : ";
		std::cout << (end - start) << std::endl;
		if (int diff = (F(list.size()) - comps) < 0)
			std::cout << "with " << diff << " discrepancy\n";
	}
}

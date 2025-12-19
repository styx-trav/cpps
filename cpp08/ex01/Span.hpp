#ifndef SPAN_HPP
# define SPAN_HPP
# include <iostream>
# include <vector>
# include <algorithm>

class Span
{
	private:
		const unsigned int sizer;
		unsigned int full;
		std::vector<int> *arr;
	public:
		Span();
		~Span();
		Span(unsigned int size);
		Span(const Span &other);
		Span &operator=(const Span &other);
		void addNumber(int num);
		void print();
		std::vector<int> softCopy();
		unsigned int shortestSpan();
		unsigned int longestSpan();
		template <typename T> void append(T begin, T end)
		{
			for (T it = begin; it != end; it++)
			{
				if (full == sizer)
					break ;
				(*arr)[full] = *it;
				full++;
			}
		};
};

#endif

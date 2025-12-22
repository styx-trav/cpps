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
		void print() const;
		std::vector<int> softCopy() const;
		unsigned int shortestSpan() const;
		unsigned int longestSpan() const;
		template <typename T> void append(T begin, T end, unsigned int size)
		{
			if (size + full > sizer)
				throw std::out_of_range("this range is too big to add to this span !\n");
			unsigned int r = full;
			for (T it = begin; it != end; it++)
			{
				if (r == sizer)
					throw std::out_of_range("this range is too big to add to this span !\n");
				(*arr)[r] = *it;
				r++;
			}
			full = r;
		};
		template <typename T> void append(T begin, unsigned int size)
		{
			if (size + full > sizer)
				throw std::out_of_range("this range is too big to add to this span !\n");
			unsigned int r = full;
			for (T it = begin; it != begin + size; it++)
			{
				if (r == sizer)
					throw std::out_of_range("this range is too big to add to this span ! liar.\n");
				(*arr)[r] = *it;
				r++;
			}
			full = r;
		};
};

#endif

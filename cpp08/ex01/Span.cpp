#include "Span.hpp"

Span::Span() : sizer(0), full(0), arr(new std::vector<int>(0))
{
	std::cout << "Span default constructor called\n";
}

Span::~Span()
{
	delete arr;
	std::cout << "Span destructor called\n";
}

Span::Span(unsigned int N) : sizer(N), full(0), arr(new std::vector<int>(N))
{
	std::cout << "Span constructor called\n";
}

Span::Span(const Span &other) : sizer(other.sizer), full(other.full), arr(new std::vector<int>(other.sizer))
{
	for (unsigned int i = 0; i != full; i++)
		(*arr)[i] = (*other.arr)[i];
	std::cout << "Span copy constructor called\n";
}

Span& Span::operator=(const Span &other)
{
	if (other.sizer != sizer)
		throw std::out_of_range("these spans are of unequal size :: assignment impossible\n");
	if (this != &other)
	{
		for (unsigned int i = 0; i != other.full ; i++)
			(*arr)[i] = (*other.arr)[i];
		full = other.full;
		std::cout << "Span assignment operator called\n";
	}
	return *this;
}

void Span::addNumber(int num)
{
	if (full == sizer)
		throw std::out_of_range("this span is full !\n");
	(*arr)[full] = num;
	full++;
}

void Span::print()
{
	for (unsigned int i = 0; i != full; i++)
		std::cout << (*arr)[i] << std::endl;
}

std::vector<int> Span::softCopy()
{
	std::vector<int> obj(full);
	//im sure theres a partial copy in there we can use instead, but lets hardcode it for now;
	for (unsigned int i = 0; i != full; i++)
		obj[i] = (*arr)[i];
	return obj;
}

//still not liking how lon and contrived this looks, but its whatever - it works; if better idea later will tweak
unsigned int Span::shortestSpan()
{
	std::vector<int> obj = this->softCopy();
	if (obj.size() < 2)
		throw std::out_of_range("not enough numbers in this span !\n");
	std::sort<std::vector<int>::iterator>(obj.begin(), obj.end());
	unsigned int res;
	for (std::vector<int>::iterator it = ++obj.begin(); it != obj.end(); it++)
	{
		unsigned int ned = *it - *(it -1);
		if (it == ++obj.begin())
			res = ned;
		else if (res > ned)
			res = ned;
	}
	return res;
}

unsigned int Span::longestSpan()
{
	std::vector<int> obj = this->softCopy();
	if (obj.size() < 2)
		throw std::out_of_range("not enough numbers in this span !\n");
	std::sort<std::vector<int>::iterator>(obj.begin(), obj.end());
	unsigned int res = obj.back() - obj.front();
	return res;
}

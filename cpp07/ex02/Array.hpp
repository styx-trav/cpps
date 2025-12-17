#ifndef ARRAY_HPP
# define ARRAY_HPP
# include <iostream>
# include <exception>

template <class T> class Array
{
	private:
		T *array;
		unsigned int sizer;
	public:
		Array(): array(new T[0]()), sizer(0)
		{
			std::cout << "creating Array (empty)\n";
		};
		~Array()
		{
			std::cout << "destroying Array\n";
			delete[] array;
		};
		Array(unsigned int n) : array(new T[n]()), sizer(n)
		{
			std::cout << "creating Array\n";
		};
		Array(const Array &other)
		{
			std::cout << "creating Array (copy)\n";
			sizer = other.sizer;
			array = new T[sizer];
			for (unsigned int i = 0; i != sizer; i++)
				array[i] = other.array[i];
		};
		Array &operator=(const Array &other)
		{
			if (this != &other)
			{
				delete[] this->array;
				sizer = other.sizer;
				array = new T[sizer]();
				for (unsigned int i = 0; i != sizer; i++)
					array[i] = other.array[i];
				std::cout << "Array assignment\n";
			}
			return *this;
		};
		T &operator[](unsigned int i)
		{
			if (i >= sizer)
				throw std::exception();
			return array[i];
		};
		unsigned int size() const {return sizer;};
		void print() const
		{
			for (unsigned int i = 0; i != sizer; i++)
	 		 std::cout << array[i] << std::endl;
		};
};

#endif

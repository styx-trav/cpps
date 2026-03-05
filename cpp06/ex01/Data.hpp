#ifndef DATA_HPP
# define DATA_HPP
# include <iostream>


class Data
{
	private:
		const std::string _name;
	public:
		int age;
		Data();
		~Data();
		Data(const std::string &name, int _age);
		Data(const Data &other);
		Data &operator=(const Data &other);
		const std::string &getName() const;
		void read() const;
};

#endif

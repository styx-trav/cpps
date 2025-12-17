#ifndef DATA_HPP
# define DATA_HPP
# include <iostream>


class Data
{
	private:
		const std::string _name;
	public:
		Data();
		~Data();
		Data(const std::string &name);
		Data(const Data &other);
		Data &operator=(const Data &other);
		const std::string &getName() const;
};

#endif

#include "CustomException.hpp"

CustomException::CustomException() : std::out_of_range("this number is out of range !") {}

CustomException::~CustomException() throw() {}

CustomException::CustomException(const CustomException &other) : std::out_of_range(other) {}

CustomException &CustomException::operator=(const CustomException &other) {if (&other != this) {std::cout << "assignment operator on custom exception\n";} return *this;}

CustomException::CustomException(const std::string &msg) : std::out_of_range(msg) {}

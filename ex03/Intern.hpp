#ifndef Intern_HPP
#define Intern_HPP
#include "Bureaucrat.hpp"

class Intern {
public:
	Intern();
	~Intern();
	Intern(const Intern& other);
	Intern& operator=(const Intern &other);
	AForm* makeForm(std::string const &formName, std::string const &target);
};

#endif
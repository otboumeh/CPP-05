#ifndef RobotomyRequestForm_HPP
#define RobotomyRequestForm_HPP
#include <iostream>
#include <string>
#include <exception>
#include <fstream>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm{
	private:
	std::string _target;
	public:

	RobotomyRequestForm(); 
	~RobotomyRequestForm();

	RobotomyRequestForm(std::string const& target);

	RobotomyRequestForm(const RobotomyRequestForm& other);             
	RobotomyRequestForm&	operator=(const RobotomyRequestForm &other);

    void execute(Bureaucrat const & executor) const;
};

#endif
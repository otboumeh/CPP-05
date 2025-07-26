#ifndef ShrubberyCreationForm_HPP
#define ShrubberyCreationForm_HPP
#include <iostream>
#include <string>
#include <exception>
#include <fstream>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm{
	private:
	std::string _target;
	public:

	ShrubberyCreationForm(); 
	~ShrubberyCreationForm();

	ShrubberyCreationForm(std::string const& target);

	ShrubberyCreationForm(const ShrubberyCreationForm& other);             
	ShrubberyCreationForm&	operator=(const ShrubberyCreationForm &other);

    void execute(Bureaucrat const & executor) const;
};

#endif
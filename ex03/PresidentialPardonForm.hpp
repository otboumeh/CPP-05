#ifndef PresidentialPardonForm_HPP
#define PresidentialPardonForm_HPP
#include <iostream>
#include <string>
#include <exception>
#include <fstream>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm{
	private:
	std::string _target;
	public:

	PresidentialPardonForm(); 
	~PresidentialPardonForm();

	PresidentialPardonForm(std::string const& target);

	PresidentialPardonForm(const PresidentialPardonForm& other);             
	PresidentialPardonForm&	operator=(const PresidentialPardonForm &other);

    void execute(Bureaucrat const & executor) const;
};

#endif
#ifndef Bureaucrat_HPP
#define Bureaucrat_HPP
#include <iostream>
#include <string>
#include <exception>
#include "Form.hpp"
class Form;

class Bureaucrat{
	private:
	std::string const _name;
	int _grade;
	public:

	Bureaucrat();                    
	~Bureaucrat();

	Bureaucrat(int grade , std::string const name);

	Bureaucrat(const Bureaucrat& other);             
	Bureaucrat&	operator=(const Bureaucrat &other);

	std::string getName() const;
	int getGrade() const;

	void incrementGrade() ;
	void decrementGrade() ;
	class GradeTooHighException : public std::exception{
		virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception{
	virtual const char* what() const throw();
	};
	void signForm(Form &form);

};
std::ostream& operator<<(std::ostream& out, const Bureaucrat& b);

#endif
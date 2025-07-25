#ifndef Form_HPP
#define Form_HPP
#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form{
    private:
    std::string const _name;
    bool              _signed;
    int const         _gradeSigned;
    int const         _gradeExecute;

    public:
    Form();
	~Form();

	Form(int const gradeSigned , int const gradeExecute, std::string const name);

	Form(const Form& other);             
	Form&	operator=(const Form &other);


    std::string getName() const;
	int getGradeSigned() const;
    int getGradeExecute() const;
    bool getSigned() const;

    void beSigned(Bureaucrat const & b);
    class GradeTooHighException : public std::exception{
		virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception{
	virtual const char* what() const throw();
	};
};
std::ostream& operator<<(std::ostream& out, const Form& b);


#endif
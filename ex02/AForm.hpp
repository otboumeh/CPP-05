#ifndef AForm_HPP
#define AForm_HPP
#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm{
    private:
    std::string const _name;
    bool              _signed;
    int const         _gradeSigned;
    int const         _gradeExecute;

    public:
    AForm();
	virtual ~AForm();

	AForm(int const gradeSigned , int const gradeExecute, std::string const name);

	AForm(const AForm& other);             
	AForm&	operator=(const AForm &other);


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
     class FormNotSignedException : public std::exception {
        virtual const char* what() const throw();
    };
    virtual void execute(Bureaucrat const & executor) const = 0 ;
};
std::ostream& operator<<(std::ostream& out, const AForm& b);


#endif
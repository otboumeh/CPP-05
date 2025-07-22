#ifndef Bureaucrat_HPP
#define Bureaucrat_HPP
#include <iostream>
#include <string>

class Bureaucrat{
	private:
	std::string name;
	public:

	Bureaucrat();                    
	~Bureaucrat();

	
	Bureaucrat(const Bureaucrat& other);             
	Bureaucrat&	operator=(const Bureaucrat &other);
};


#endif
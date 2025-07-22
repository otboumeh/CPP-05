#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(){
	std::cout<<"Bureaucrat Constructor called"<<std::endl;
}

Bureaucrat::~Bureaucrat(){
	std::cout<<"Bureaucrat Destructor called"<<std::endl;
}
Bureaucrat::Bureaucrat(int grade , std::string const name){
	std::cout<<""<<std::endl;
}
Bureaucrat::Bureaucrat(const Bureaucrat& other) {
//To do 
}           

Bureaucrat&Bureaucrat::	operator=(const Bureaucrat &other){
// to do
}

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(){
	std::cout<<"Bureaucrat Constructor called"<<std::endl;
}

Bureaucrat::~Bureaucrat(){
	std::cout<<"Bureaucrat Destructor called"<<std::endl;
}
Bureaucrat::Bureaucrat(int grade , std::string const name): _name(name){
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	_grade = grade;
	std::cout << "Bureaucrat constructor called for " << _name << " with grade " << _grade << std::endl;
}
Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name),_grade(other._grade) {
	std::cout << "Copy constructor called for " << _name << std::endl;
}           

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    if (this == &other)
        return *this;

    _grade = other._grade;
    std::cout << "Assignment operator called for " << _name << std::endl;
    return *this;
}

int Bureaucrat::getGrade()const{
	return _grade;
}
std::string Bureaucrat::getName() const{
	return _name;
}
void Bureaucrat::incrementGrade(){
	if (_grade - 1 < 1)
		throw GradeTooHighException();
	_grade--;
}

void Bureaucrat::decrementGrade(){
	if (_grade + 1 > 150)
		throw GradeTooLowException();
	_grade++;
}


const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade is too high";
}
const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade is too low";
}
std::ostream& operator<<(std::ostream& out, const Bureaucrat& b) {
    out << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return out;
}

void Bureaucrat::signForm(AForm &Aform) {
    try {
        Aform.beSigned(*this);
        std::cout << _name << " signed " << Aform.getName() << std::endl;
    } catch (std::exception &e) {
        std::cout << _name << " couldn't sign " << Aform.getName()
                  << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const & form) const {
    try {
        form.execute(*this);  // Try to execute the form
        std::cout << this->getName() << " executed " << form.getName() << std::endl;
    } catch (std::exception const &e) {
        std::cout << this->getName() << " couldn't execute " << form.getName()
                  << " because " << e.what() << std::endl;
    }
}
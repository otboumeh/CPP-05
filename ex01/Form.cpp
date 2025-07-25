#include "Form.hpp"

Form::Form() : _name("Unnamed"), _signed(false), _gradeSigned(150), _gradeExecute(150) {
    std::cout << "Default Form constructor called" << std::endl;
}

Form::~Form(){
	std::cout<<"Form Destructor called"<<std::endl;
}
Form::Form(int const gradeSigned , int const gradeExecute, std::string const name)
    : _name(name), _signed(false), _gradeSigned(gradeSigned), _gradeExecute(gradeExecute) {
    if (gradeSigned < 1 || gradeExecute < 1)
        throw GradeTooHighException();
    else if (gradeSigned > 150 || gradeExecute > 150)
        throw GradeTooLowException();

    std::cout << "Form constructor called for " << _name 
              << ", requires grade " << _gradeSigned 
              << " to sign and " << _gradeExecute << " to execute." << std::endl;
}

Form::Form(const Form& other)
  : _name(other._name),
    _signed(other._signed),
    _gradeSigned(other._gradeSigned),
    _gradeExecute(other._gradeExecute)
{
    std::cout << "Copy constructor called for " << _name << std::endl;
}


Form& Form::operator=(const Form& other) {
    if (this == &other)
        return *this;

    this->_signed = other._signed;
    std::cout << "Assignment operator called for " << _name << std::endl;
    return *this;
}


std::string Form::getName() const{
    return _name;
}

int Form::getGradeSigned() const{
    return _gradeSigned;
}

int Form::getGradeExecute() const{
    return _gradeExecute;
}
bool Form::getSigned() const{
    return _signed;
}
const char* Form::GradeTooHighException::what() const throw() {
    return "Form grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Form grade is too low!";
}
void Form::beSigned(Bureaucrat const& b) {
    if (b.getGrade() > _gradeSigned)
        throw GradeTooLowException();
    _signed = true;
}
std::ostream& operator<<(std::ostream& out, const Form& form) {
    out << "Form " << form.getName()
        << ", signed: " << (form.getSigned() ? "yes" : "no")
        << ", grade required to sign: " << form.getGradeSigned()
        << ", grade required to execute: " << form.getGradeExecute();
    return out;
}
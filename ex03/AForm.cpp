#include "AForm.hpp"

AForm::AForm() : _name("Unnamed"), _signed(false), _gradeSigned(150), _gradeExecute(150) {
    std::cout << "Default AForm constructor called" << std::endl;
}

AForm::~AForm(){
	std::cout<<"AForm Destructor called"<<std::endl;
}
AForm::AForm(int const gradeSigned , int const gradeExecute, std::string const name)
    : _name(name), _signed(false), _gradeSigned(gradeSigned), _gradeExecute(gradeExecute) {
    if (gradeSigned < 1 || gradeExecute < 1)
        throw GradeTooHighException();
    else if (gradeSigned > 150 || gradeExecute > 150)
        throw GradeTooLowException();

    std::cout << "AForm constructor called for " << _name 
              << ", requires grade " << _gradeSigned 
              << " to sign and " << _gradeExecute << " to execute." << std::endl;
}

AForm::AForm(const AForm& other)
  : _name(other._name),
    _signed(other._signed),
    _gradeSigned(other._gradeSigned),
    _gradeExecute(other._gradeExecute)
{
    std::cout << "Copy constructor called for " << _name << std::endl;
}


AForm& AForm::operator=(const AForm& other) {
    if (this == &other)
        return *this;

    this->_signed = other._signed;
    std::cout << "Assignment operator called for " << _name << std::endl;
    return *this;
}


std::string AForm::getName() const{
    return _name;
}

int AForm::getGradeSigned() const{
    return _gradeSigned;
}

int AForm::getGradeExecute() const{
    return _gradeExecute;
}
bool AForm::getSigned() const{
    return _signed;
}
const char* AForm::GradeTooHighException::what() const throw() {
    return "AForm grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "AForm grade is too low!";
}
const char* AForm::FormNotSignedException::what() const throw() {
    return "AForm cannot be executed because it is not signed!";
}

void AForm::beSigned(Bureaucrat const& b) {
    if (b.getGrade() > _gradeSigned)
        throw GradeTooLowException();
    _signed = true;
}
std::ostream& operator<<(std::ostream& out, const AForm& Aform) {
    out << "AForm " << Aform.getName()
        << ", signed: " << (Aform.getSigned() ? "yes" : "no")
        << ", grade required to sign: " << Aform.getGradeSigned()
        << ", grade required to execute: " << Aform.getGradeExecute();
    return out;
}
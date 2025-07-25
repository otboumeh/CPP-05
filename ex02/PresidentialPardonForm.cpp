#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
    : AForm(25, 5, "PresidentialPardonForm"), _target("Target") {
    std::cout << "PresidentialPardonForm default constructor called for: " << _target << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(){
    std::cout<<"PresidentialPardonForm Destructor called"<<std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const& target):AForm(25,5,"PresidentialPardonForm"), _target(target){
    std::cout << "PresidentialPardonForm constructor called for target: " << _target << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
    : AForm(other), _target(other._target) {
    std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
}
      
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
    if (this == &other)
        return *this;

    AForm::operator=(other);
    _target = other._target;
    return *this;
}
void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
    if (!getSigned())
        throw FormNotSignedException();
    if (executor.getGrade() > getGradeExecute())
        throw GradeTooLowException();
    std::cout << _target<<" has been pardoned by Zaphod Beeblebrox" << std::endl;
}


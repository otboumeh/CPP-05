#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
    : AForm(72, 45, "RobotomyRequestForm"), _target("Target") {
    std::cout << "RobotomyRequestForm default constructor called for: " << _target << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(){
    std::cout<<"RobotomyRequestForm Destructor called"<<std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const& target):AForm(72,45,"RobotomyRequestForm"), _target(target){
    std::cout << "RobotomyRequestForm constructor called for target: " << _target << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
    : AForm(other), _target(other._target) {
    std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}
      
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
    if (this == &other)
        return *this;

    AForm::operator=(other);
    _target = other._target;
    return *this;
}
void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
    if (!getSigned())
        throw FormNotSignedException();
    if (executor.getGrade() > getGradeExecute())
        throw GradeTooLowException();

    std::cout << "* drilling noises *" << std::endl;

    if (rand() % 2 == 0)
        std::cout << _target << " has been robotomized successfully!" << std::endl;
    else
        std::cout << "Robotomy failed on " << _target << "." << std::endl;
}


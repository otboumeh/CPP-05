#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm(145, 137, "ShrubberyCreationForm"), _target("Target") {
    std::cout << "Shrubbery default constructor called for: " << _target << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
    std::cout<<"Shruberry Destructor called"<<std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const& target):AForm(145,137,"ShrubberyCreationForm"), _target(target){
    std::cout << "Shrubbery constructor called for target: " << _target << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    : AForm(other), _target(other._target) {
    std::cout << "Shrubbery copy constructor called" << std::endl;
}
      
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
    if (this == &other)
        return *this;

    AForm::operator=(other);
    _target = other._target;
    return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
    if (!getSigned())
        throw FormNotSignedException();
    if (executor.getGrade() > getGradeExecute())
        throw GradeTooLowException();

    std::ofstream file((_target + "_shrubbery").c_str());
    if (!file) {
        std::cerr << "Failed to open file\n";
        return;
    }

    file << "       _-_\n"
            "    /~~   ~~\\\n"
            " /~~         ~~\\\n"
            "{               }\n"
            " \\  _-     -_  /\n"
            "   ~  \\\\ //  ~\n"
            "_- -   | | _- _\n"
            "  _ -  | |   -_\n"
            "      // \\\\" << std::endl;

    file.close();
    std::cout << _target << "_shrubbery created with ASCII trees!" << std::endl;
}
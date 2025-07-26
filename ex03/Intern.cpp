#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

static AForm* createShrubbery(std::string const &target) {
    return new ShrubberyCreationForm(target);
}

static AForm* createRobotomy(std::string const &target) {
    return new RobotomyRequestForm(target);
}

static AForm* createPresidential(std::string const &target) {
    return new PresidentialPardonForm(target);
}

Intern::Intern() {}
Intern::Intern(const Intern&) {}
Intern::~Intern() {}
Intern &Intern::operator=(const Intern&) { return *this; }

AForm* Intern::makeForm(std::string const &formName, std::string const &target) {
    std::string formNames[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
};

AForm* (*formCreators[3])(std::string const &) = {
        createShrubbery,
        createRobotomy,
        createPresidential
};

for (int i = 0; i < 3; ++i) {
    if (formName == formNames[i]) {
        std::cout << "Intern creates " << formName << std::endl;
        return formCreators[i](target);
    }
}

std::cout << "Intern: form \"" << formName << "\" does not exist." << std::endl;
return NULL;
}

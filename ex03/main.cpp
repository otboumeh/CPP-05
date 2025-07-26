#include <iostream>
#include "Intern.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"

int main() {
    Intern intern;

    std::cout << "\n=== Valid Form: Robotomy Request ===" << std::endl;
    AForm* form1 = intern.makeForm("robotomy request", "Bender");

    if (form1) {
        std::cout << *form1 << std::endl;
        delete form1;
    }

    std::cout << "\n=== Valid Form: Shrubbery Creation ===" << std::endl;
    AForm* form2 = intern.makeForm("shrubbery creation", "Home");

    if (form2) {
        std::cout << *form2 << std::endl;
        delete form2;
    }

    std::cout << "\n=== Valid Form: Presidential Pardon ===" << std::endl;
    AForm* form3 = intern.makeForm("presidential pardon", "Fry");

    if (form3) {
        std::cout << *form3 << std::endl;
        delete form3;
    }

    std::cout << "\n=== Invalid Form: Fire Request ===" << std::endl;
    AForm* form4 = intern.makeForm("fire request", "Leela");

    if (!form4) {
        std::cout << "Form creation failed.\n";
    }

    return 0;
}

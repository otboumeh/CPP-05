#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    try {
        // Bureaucrats with different grades
        Bureaucrat boss(1, "Boss");
        Bureaucrat intern(150,"Intern");

        // Create forms
        ShrubberyCreationForm shrub("Home");
        RobotomyRequestForm robot("Bender");
        PresidentialPardonForm pardon("Rick");

        std::cout << "\n--- Signing Forms ---" << std::endl;
        boss.signForm(shrub);      // should succeed
        boss.signForm(robot);      // should succeed
        boss.signForm(pardon);     // should succeed

        std::cout << "\n--- Executing Forms with Intern (should fail) ---" << std::endl;
        intern.executeForm(shrub);
        intern.executeForm(robot);
        intern.executeForm(pardon);

        std::cout << "\n--- Executing Forms with Boss (should succeed) ---" << std::endl;
        boss.executeForm(shrub);
        boss.executeForm(robot);
        boss.executeForm(pardon);
    }
    catch (const std::exception& e) {
        std::cerr << "Exception in main: " << e.what() << std::endl;
    }

    return 0;
}

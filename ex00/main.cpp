#include "Bureaucrat.hpp"

int main() {
    try {
        std::cout << "Creating bureaucrat Alice with grade 2" << std::endl;
        Bureaucrat alice(2, "Alice");
        std::cout << alice << std::endl;

        std::cout << "\nIncrementing Alice's grade (should succeed)" << std::endl;
        alice.incrementGrade();
        std::cout << alice << std::endl;

        std::cout << "\nIncrementing Alice's grade (should throw GradeTooHighException)" << std::endl;
        alice.incrementGrade(); // This should throw because grade would go from 1 to 0
    }
    catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\nCreating bureaucrat Bob with grade 149" << std::endl;
    Bureaucrat bob(149, "Bob");
    std::cout << bob << std::endl;

    try {
        std::cout << "\nDecrementing Bob's grade (should succeed)" << std::endl;
        bob.decrementGrade();
        std::cout << bob << std::endl;

        std::cout << "\nDecrementing Bob's grade (should throw GradeTooLowException)" << std::endl;
        bob.decrementGrade(); // This should throw because grade would go from 151
    }
    catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\nTesting copy constructor:" << std::endl;
    Bureaucrat copyBob(bob);
    std::cout << copyBob << std::endl;

    std::cout << "\nTesting assignment operator:" << std::endl;
    Bureaucrat charlie(50, "Charlie");
    std::cout << "Before assignment: " << charlie << std::endl;
    charlie = bob;
    std::cout << "After assignment: " << charlie << std::endl;

    std::cout << "\nTesting invalid grade creation (should throw):" << std::endl;
    try {
        Bureaucrat invalid(0, "Invalid"); // Grade too high
    }
    catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    try {
        Bureaucrat invalid2(200, "Invalid2"); // Grade too low
    }
    catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\nAll tests done!" << std::endl;
    return 0;
}

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    std::cout << "===== Valid Signing Test =====" << std::endl;
    try {
        Bureaucrat bob( 50, "Bob");
        Form taxForm(100, 50, "Tax Form");
        std::cout << taxForm << std::endl;
        bob.signForm(taxForm);
        std::cout << taxForm << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n===== Grade Too Low to Sign Test =====" << std::endl;
    try {
        Bureaucrat jim(120,"Jim");
        Form secretForm(100, 50, "Secret Form");
        std::cout << secretForm << std::endl;
        jim.signForm(secretForm);
        std::cout << secretForm << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n===== Invalid Form Creation Test =====" << std::endl;
    try {
        Form invalidForm(0, 200, "Invalid Form");  // grade too high and too low
    } catch (std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n===== Already Signed Form Test =====" << std::endl;
    try {
        Bureaucrat alice( 1,"Alice");
        Form permit(10, 20, "Building Permit");
        alice.signForm(permit);  // First time
        alice.signForm(permit);  // Try again
    } catch (std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n===== All tests completed =====" << std::endl;

    return 0;
}

#include <iostream>

#include "TestScurt.hpp"
#include "TestExtins.hpp"

int main() {
    testAll();
    testAllExtins();
    std::cout << "Finished Tests!\n" << std::endl;
    testCheieMaxima();
    std::cout << "Test functionalitate noua ok!\n" << std::endl;
}

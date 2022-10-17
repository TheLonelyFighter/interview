#include<iostream>

int main(int argc, char* argv[]) {
    int number = 10;

    std::cout << sizeof(uint) << std::endl;

    if (argc != 2) {
        std::cout << "Command: ./factorial <positive integer>" << std::endl;
        return 1;
    }

    try {
        number = std::stoi(argv[1]);
    } catch (std::invalid_argument& e) {
        std::cout << "Error: Invalid argument" << std::endl;
        return 2;
    } catch (std::out_of_range& e) {
        std::cout << "Error: Out of range" << std::endl;
        return 3;
    } catch (...) {
        std::cout << "Error: Unknown" << std::endl;
        return 4;
    }
    
    if (number < 0) {
        std::cout << "Error: Input value must be positive" << std::endl;
        return 3;
    }
    else if (number == 0) {
        std::cout << "1" << std::endl;
    } else {
        uint factorial = 1;
        for (uint i = 1; i <= number; i++) {
            factorial *= i;
        }
        std::cout << factorial << std::endl;
    }

    return 0;
}
#include<iostream>
#include<string>
#include<cmath> // libraries included with <> are system libraries
#include"utils.h" // libraries included with "" are local libraries

int main(int argc, char* argv[])
{
    if (argc < 2) 
    {
        // report version
        std::cout << argv[0] << " Version " << interview_code_VERSION_MAJOR << "."
              << interview_code_VERSION_MINOR << std::endl;
        std::cout << "Usage: " << argv[0] << " number" << std::endl;
        return 1;
    
    }

    print_version();

    const double inputValue = std::stod(argv[1]);

    if (inputValue < 0)
    {
        std::cout << "Error: Input value must be positive" << std::endl;
        return 1;
    }

    const double outputValue = sqrt(inputValue);

    std::cout << "The square root of " << inputValue << " is " << outputValue << std::endl;
    return 0;
}
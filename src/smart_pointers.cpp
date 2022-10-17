#include<iostream>
#include <memory>


int main() {
    
    
    int* int_p_raw = nullptr;

    std::shared_ptr<int> int_p_unique = std::make_shared<int>(5);
    //std::cout << "int_p_unique: " << int_p_unique.get() << " value: " << *int_p_unique <<std::endl;

    // c++ allows to use unintiliazed pointer --> it is very bad practice
    if (int_p_raw != nullptr) {
        std::cout << "int_p_raw: " << int_p_raw << " value: " << *int_p_raw <<std::endl;
    }
    else {
        std::cout << "int_p_raw is nullptr" << std::endl;
    }
    // smart pointers are initialized with nullptr, so trying to access them will result in segfault
    if (int_p_unique) {
        std::cout << "int_p_unique: " << int_p_unique.get() << " value: " << *int_p_unique <<std::endl;
    }
    else {
        std::cout << "int_p_unique is null" << std::endl;
    }

    // smart pointers are deleted automatcally after being deallocated, phew no more memory leaks
    int_p_unique.reset();

    
    // Don't forget to delete raw pointers!
    // If you try to delete a smart pointer, you will get a compile error
    // If you try to delete an uninitialized pointer, you will get a segfault, always use nullptr
    delete int_p_raw;  
    return 0;
}

// int_p_unique is deleted automatically here.

// Lesson learned: just don't use raw pointers, use smart pointers instead.
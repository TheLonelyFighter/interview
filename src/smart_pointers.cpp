#include<iostream>
#include <memory>


int main() {
    
    
    int* int_p_raw;

    std::shared_ptr<int> int_p_unique;
    //std::cout << "int_p_unique: " << int_p_unique.get() << " value: " << *int_p_unique <<std::endl;

    // c++ allows to use unintiliazed pointer --> it is very bad practice
    std::cout << "int_p_raw: " << int_p_raw << " value: " << *int_p_raw <<std::endl;
    
    // smart pointers are initialized with nullptr, so trying to access them will result in segfault
    if (int_p_unique) {
        std::cout << "int_p_unique: " << int_p_unique.get() << " value: " << *int_p_unique <<std::endl;
    }
    else {
        std::cout << "int_p_unique is null" << std::endl;
    }

    // smart pointers are destroyed after being deallocated, phew 
    int_p_unique.reset();

    //std::unique_ptr<std::string> song_smart(new std::string(L"Nothing on You", L"Bruno Mars"));

    // Use song2...
    //std::cout << *song_smart << std::endl;
    //...
    // Don't forget to delete!
   // delete song_raw;  
    return 0;
}

// song2 is deleted automatically here.
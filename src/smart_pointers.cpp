#include<iostream>
#include <memory>


class Entity
{
    public:
        Entity()
        {
            std::cout << "Created Entity!" << std::endl;
        }
        ~Entity()
        {
            std::cout << "Destroyed Entity!" << std::endl;
        }
        void Print()
        {
            std::cout << "Hello World!" << std::endl;
        }

};

int main() {

    //std::cin.get();
    {
        std::unique_ptr<Entity> entity = std::make_unique<Entity>();
        entity->Print();
    }// entity is destroyed here, no memory leak headaches
    
    int* int_p_raw = nullptr;

    // std::make_unique is available in C++14, it does now allow copying the pointer
    std::unique_ptr<int> int_p_unique = std::make_unique<int>(5);

    // unique_pt does now allow copying the pointer, because the copy constructor gets deleted when creating the object (it's for safety reasons)
    // std::shared_ptr<int> int_p_unique_copy = int_p_unique; // compile error
    //older alternative, but does not provide exception safety if constructor throws exception
    std::shared_ptr<int> int_p_shared = std::shared_ptr<int>(new int(5));
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
// Smart pointers are safer, easier to use and they are deleted automatically.
// Smart pointers are not a replacement for raw pointers, they are just a wrapper around them.
// Using smart pointers is a good practice, but it is not a requirement.
// You can use raw pointers if you want to, but you have to be careful and delete them manually.
// Using smart pointer means you don't have to use "new" and "delete" keywords anymore.
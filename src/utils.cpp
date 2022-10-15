#include"utils.h"
#include<iostream>

void print_version()
{
  std::cout << "This is a function defined in utils.cpp.\nVersion: " 
            << interview_code_VERSION_MAJOR << "."
            << interview_code_VERSION_MINOR << std::endl;
}
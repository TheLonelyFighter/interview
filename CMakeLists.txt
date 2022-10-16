cmake_minimum_required(VERSION 3.0)
project(interview_code VERSION 1.0.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
#configure_file(src/Config.h.in src/Config.h)


add_executable(review src/review.cpp)
add_executable(string_processing src/string_processing.cpp src/utils.h src/utils.cpp)
add_executable(vector_list src/vector_list.cpp)
add_executable(class_example src/class_example.cpp)
#target_link_libraries(string_processing 
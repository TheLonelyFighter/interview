cmake_minimum_required(VERSION 3.0)
project(interview_code VERSION 1.0.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
add_compile_options(-std=c++11)
#configure_file(src/Config.h.in src/Config.h)


# add_executable(hello_world src/hello_world.cpp)
# add_executable(string_processing src/string_processing.cpp src/utils.h src/utils.cpp)
# add_executable(vector_list src/vector_list.cpp)
# add_executable(class_example src/class_example.cpp)
# add_executable(football src/football.cpp)
# add_executable(factorial src/factorial.cpp)
# add_executable(smart_pointers src/smart_pointers.cpp)
add_executable(sets src/sets.cpp)
add_executable(football_maps src/football_maps.cpp)
#target_link_libraries(string_processing 
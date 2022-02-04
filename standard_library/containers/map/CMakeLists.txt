cmake_minimum_required(VERSION 3.10)

project(std_map_exercises LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -O3")

set(exercies_names
        assignment_operator
        at
        clear
        constructor
        emplace
        emplace_hint
        empty
        equal_operator
        erase
        insert
        iterators
        max_size
        size
        square_bracket_operator)

foreach(ex_name ${exercies_names})
    add_executable(${ex_name} ${ex_name}.cpp)
endforeach()

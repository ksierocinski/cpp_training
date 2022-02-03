cmake_minimum_required(VERSION 3.10)

project(std_vector_exercises LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -O3")

set(exercies_names
        assignment_operator
        at
        back
        capacity
        clear
        constructor
        data
        emplace_back
        emplace
        empty
        equal_operator
        erase
        front
        insert
        iterators
        max_size
        pop_back
        push_back
        reserve
        resize
        shrink_to_fit
        size
        square_bracket_operator
        swap)

foreach(ex_name ${exercies_names})
    add_executable(${ex_name} ${ex_name}.cpp)
endforeach()

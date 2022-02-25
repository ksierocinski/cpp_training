#include <iostream>
#include <vector>

/*****************************************************************************
 * std::vector<T,Allocator>::operator=
 * 
 * 
 * Use operator= to initialize vectors:
 *  1. Copy from other vector,
 *  2. Move values from other vector (hint: use std::move()),
 *  3. Use initializer list  
 * For every case print base and currently initilized vector
 *
 ****************************************************************************/ 

int main() {
    std::vector<std::string> v1 {"this", "is", "base", "vector"};
    std::cout << "Elements in vector v1: | ";
    for(auto el: v1){
        std::cout << el << " | ";
    }
    
    return 0;
}

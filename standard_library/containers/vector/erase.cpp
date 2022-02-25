#include <iostream>
#include <vector>

/*****************************************************************************
 * std::vector<T,Allocator>::erase
 * 1) Erase the element at some position from the first vector - after that print this vector, and its size 
 * 2) Erase some range of elements from second vector - after that print this vector, and its size 
 * 
 ****************************************************************************/ 

void print_vector(std::vector<int> &v){
    for(auto value: v){
        std::cout << " | " << value; 
    }
    std::cout << " | " << std::endl;
}

int main() {
    std::vector<int> first_vector(20,1);
    std::vector<int> second_vector(20,2);

    std::cout << "Vectors before erase operations:" << std::endl;
    print_vector(first_vector);
    print_vector(second_vector);

    //Your code here

    
    //
    
    std::cout << "\nVectors after erase operations: " << std::endl;
    print_vector(first_vector);
    print_vector(second_vector);

    return 0;
}

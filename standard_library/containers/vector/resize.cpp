#include <iostream>
#include <vector>

/*****************************************************************************
 * std::vector<T,Allocator>::resize
 * Resize given vector:
 * 1) enlarge for some amount with default values,
 * 2) enlarge for some amount with specific values,
 * 3) shrink to some size
 * After every resize operation print vector
 ****************************************************************************/ 

void print_vector(const std::vector<int> &v){
    for(int el : v){
        std::cout << el << " ";
    }
    std::cout << std::endl;
}

int main() {


    return 0;
}

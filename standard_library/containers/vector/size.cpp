#include <iostream>
#include <vector>

/*****************************************************************************
 * std::vector<T,Allocator>::size
 * Print size of every given vector
 * 
 ****************************************************************************/ 

int main() {
    std::vector<int> v1;
    std::vector<int> v2 (20);
    std::vector<int> v3 {20} ;
    std::vector<int> v4 (10,4);
    std::vector<int> v5 {10,4};


    return 0;
}

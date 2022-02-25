#include <iostream>
#include <vector>

/*****************************************************************************
 * std::vector<T,Allocator>::swap
 * Swap content of two given vectors
 * after switch check what iterators pointing at, 
 * What can you say about it?
 ****************************************************************************/ 

void print_vectors(std::vector<int> &v1, std::vector<int> &v2, std::vector<int>::iterator &it1, std::vector<int>::iterator &it2){
    std::cout << "{ ";
    for(auto el : v1){
        std::cout << el << " ";
    } 
    std::cout << "} ";
    std::cout << "{ ";
    for(auto el : v2){
        std::cout << el << " ";
    } 
    std::cout << "} " << (*it1) << " " << (*it2) << std::endl; 
}

int main() {
    std::vector<int> v1 {1,2,3,4,5};
    std::vector<int> v2 {6,7,7};

    std::vector<int>::iterator it1 = v1.begin();
    std::vector<int>::iterator it2 = v2.begin();

    print_vectors(v1, v2, it1, it2);

   //you code here
    

    
    return 0;
}

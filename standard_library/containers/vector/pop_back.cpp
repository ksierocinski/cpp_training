#include <iostream>
#include <vector>

/*****************************************************************************
 * std::vector<T,Allocator>::pop_back
 * Benchamark pop_back and erase (evry time erase only last element from vector)
 * 
 ****************************************************************************/ 

void benchmark_pop(std::vector<int> &v){

}

void benchmark_erase(std::vector<int> &v){
    
}

int main() {
    std::vector<int> pop_vector (1024*1024);
    std::vector<int> erase_vector (1024*1024);


    benchmark_pop(pop_vector);
    benchmark_erase(erase_vector);

    return 0;
}

#include <iostream>
#include <vector>

/*****************************************************************************
 * std::vector<T,Allocator>::operator[]
 * Benchmark access time in vector using at() member function and sqaure bracket operator (operator[])
 * 
 ****************************************************************************/ 

void benchmark_operator(std::vector<int> &v){

}

void benchmark_at(std::vector<int> &v){
    
}

int main() {

    std::vector<int> v (1024, 3);


    //benchmark_operator(v);
    //benchmark_at(v);

    return 0;
}

#include <iostream>
#include <vector>
#include <chrono>

/*****************************************************************************
 * std::vector<T,Allocator>::insert
 * 
 * Benchmark inserting element to the vector.
 * 
 * Analize the results.
 * 
 ****************************************************************************/ 

void benchamark_insert_front(std::vector<double>& v)
{
    auto it = v.begin();
    auto start_time = std::chrono::high_resolution_clock::now();
    v.insert(it, 20.1);
    auto stop_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> benchmark_duration = stop_time - start_time;
    std::cout << "insert_front benchmark: " << benchmark_duration.count() << std::endl;

}

void benchamark_insert_middle(std::vector<double>& v)
{
    auto it = v.begin() + v.size() / 2; 
    auto start_time = std::chrono::high_resolution_clock::now();
    v.insert(it, 20.1);
    auto stop_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> benchmark_duration = stop_time - start_time;
    std::cout << "insert_middle benchmark: " << benchmark_duration.count() << std::endl;
    
}

void benchamark_insert_end(std::vector<double>& v)
{
    auto it = v.end();
    auto start_time = std::chrono::high_resolution_clock::now();
    v.insert(it, 20.1);
    auto stop_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> benchmark_duration = stop_time - start_time;
    std::cout << "insert_end benchmark: " << benchmark_duration.count() << std::endl;
}


int main() {
    std::vector<double> v(1024*1024);
    v.reserve(v.capacity() + 3);
    // std::cout << v.size() << " : " << v.capacity() << std::endl;
    

    benchamark_insert_front(v);

    benchamark_insert_middle(v);

    benchamark_insert_end(v);
    
    
    return 0;
}

/**********************************
Results
insert_front benchmark: 4.5697
insert_middle benchmark: 0.8153
insert_end benchmark: 0.0001
**********************************/

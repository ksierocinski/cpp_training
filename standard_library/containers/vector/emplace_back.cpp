#include <array>
#include <iostream>
#include <vector>
#include <chrono>
#include<iomanip>

/*****************************************************************************
 * std::vector<T,Allocator>::emplace_back
 * 
 * Benchmark different approaches to adding an element at the back of vector.
 * 
 * Analize the results.
 ****************************************************************************/ 

void benchmark_emplace_back()
{
    std::vector<std::vector<double>> v;
    static const size_t size = 1024UL;
    static const double default_value = 42.42;
    std::vector<double> v_to_add(size, default_value); // 1024 elements with 42.42 value
    
    // benchmark emplace_back(v_to_add)
    auto start_time = std::chrono::high_resolution_clock::now();
    for(int i = 0 ; i<1000;i++){
    v.emplace_back(v_to_add);
    }
    auto stop_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> emplace_benchmark_duration = stop_time - start_time;
    std::cout << "benchmark emplace_back(v_to_add): " << emplace_benchmark_duration.count() << std::endl;

    // benchmark emplace_back(size, default_value)
    start_time = std::chrono::high_resolution_clock::now();
    for(int i = 0 ; i<1000;i++){
    v.emplace_back(size);
    }
    stop_time = std::chrono::high_resolution_clock::now();
    emplace_benchmark_duration = stop_time - start_time;
    std::cout << "benchmark emplace_back(size, default_value): " << emplace_benchmark_duration.count()<< std::endl<<std::endl;

}

void benchmark_push_back()
{
    
    std::vector<std::vector<double>> v;
    static const size_t size = 1024UL;
    static const double default_value = 42.42;
    std::vector<double> v_to_add(size, default_value); // 1024 elements with 42.42 value
    
    // benchmark push_back(v_to_add)
    auto start_time = std::chrono::high_resolution_clock::now();
    for(int i = 0 ; i<1000;i++){
    v.push_back(v_to_add);
    }
    auto stop_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> push_benchmark_duration = stop_time - start_time;
    std::cout << "benchmark push_back(v_to_add): " << push_benchmark_duration.count() << std::endl;

    //benchmark push_back(size, default_value)
    start_time = std::chrono::high_resolution_clock::now();
    for(int i = 0 ; i<1000;i++){
    v.push_back(std::vector<double>(size));
    }
    stop_time = std::chrono::high_resolution_clock::now();
    push_benchmark_duration = stop_time - start_time;
    std::cout << "benchmark push_back(size, default_value): " << push_benchmark_duration.count() <<std::endl;
    
}

int main() {
    
    
    benchmark_emplace_back();
    benchmark_push_back();
    


    return 0;
}

/**********************
Results
benchmark emplace_back(v_to_add): 0.0054
benchmark emplace_back(size, default_value): 0.0098

benchmark push_back(v_to_add): 0.0007
benchmark push_back(size, default_value): 0.0006
***************************/

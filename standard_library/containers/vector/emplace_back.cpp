#include <array>
#include <iostream>
#include <vector>

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

    // benchmark emplace_back(size, default_value)

}

void benchmark_push_back()
{
    std::vector<std::vector<double>> v;
    static const size_t size = 1024UL;
    static const double default_value = 42.42;
    
    
    // benchmark push_back(v_to_add)

    // benchmark push_back(size, default_value)
    
}

int main() {
    return 0;
}

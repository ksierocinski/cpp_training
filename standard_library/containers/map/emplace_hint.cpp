#include <iostream>
#include <map>
#include <unordered_map>
#include <chrono>

/*****************************************************************************
 * std::map<Key, T>::emplace_hint
 * std::unordered_map<Key, T>::emplace_hint
 * 
 * Benchmark different cases of emplacing 1024*1024 elements:
 * 1. use emplace() member function
 * 2. use emplace_hint() where element will be added at the end and hint also
 *    points to the end
 * 3. use emplace_hint() where element will be added at the end, but hint 
 *    points to the start
 * 
 * Analize the results.
 * 
 ****************************************************************************/ 
void print_map(const std::map<int,std::string>&m){
    for(auto it = m.begin(); it != m.end(); ++it){
        std::cout << "Key: " << it -> first << " | Value: " << it->second << std::endl;
    }
    std::cout<<std::endl;
}

int main() {
    int operations = 50000;

    std::map<int,std::string> m1;
    auto start_time = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < operations; ++i){
        m1.emplace(i, "sdf");
    }
    auto stop_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> emplace_benchmark_duration = stop_time - start_time;
    std::cout << "benchmark emplace: " << emplace_benchmark_duration.count() << std::endl;
    std::cout<<std::endl;
    // print_map(m1);

    std::map<int,std::string> m2;
    start_time = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < operations; ++i){
        auto it2 = m2.end();
        m2.emplace_hint(it2, i, "grtohjoi");
    }
    stop_time = std::chrono::high_resolution_clock::now();
    emplace_benchmark_duration = stop_time - start_time;
    std::cout << "benchmark emplace_hint (hint points at end): " << emplace_benchmark_duration.count()<< std::endl<<std::endl;
    // print_map(m2);

    std::map<int,std::string> m3;
    start_time = std::chrono::high_resolution_clock::now();
    
    for(int i = 0; i < operations; ++i){   
        auto it3 = m3.begin();   
        m3.emplace_hint(it3, i, "fessdfi");
    }
    stop_time = std::chrono::high_resolution_clock::now();
    emplace_benchmark_duration = stop_time - start_time;
    std::cout << "benchmark emplace_hint (hint points at start): " << emplace_benchmark_duration.count()<< std::endl<<std::endl;
    // print_map(m3);

    

    return 0;
}
/*********************************************************
results fo 50k iterations
benchmark emplace: 9.6478

benchmark emplace_hint (hint points at end): 5.4131

benchmark emplace_hint (hint points at start): 11.6027
**********************************************************/

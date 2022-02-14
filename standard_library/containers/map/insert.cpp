
#include <cstdlib>
#include <iostream>
#include <map>
#include <unordered_map>
#include <chrono>
#include <vector>

/*****************************************************************************
 * std::map<Key, T>::insert
 * std::unordered_map<Key, T>::insert
 * 
 * Benchmark inserting element to the map and unordered_map.
 * 
 * Analize the results. What can you say about the complexity?
 * 
 ****************************************************************************/ 

int iterations = 1000;

void benchamark_map_insert(std::map<int, double>& map)
{
        auto start_time = std::chrono::high_resolution_clock::now();
        for(int i = 0; i < iterations; ++i){
            map.insert({rand(), (double)rand() / RAND_MAX});
        }
        auto stop_time = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> map_benchmark_duration = stop_time - start_time;
        std::cout << "map benchmark: " << map_benchmark_duration.count() << std::endl;
        std::cout<<std::endl;
}

void benchamark_unordered_map_insert(std::unordered_map<int, double>& umap)
{
        auto start_time = std::chrono::high_resolution_clock::now();
        for(int i = 0; i < iterations; ++i){
            umap.insert({rand(), (double)rand() / RAND_MAX});
        }
        auto stop_time = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> umap_benchmark_duration = stop_time - start_time;
        std::cout << "umap benchmark: " << umap_benchmark_duration.count() << std::endl;
        std::cout<<std::endl;
}

void benchamark_map_find_element(std::map<int,double> &map, std::vector<int>&v){
    auto start_time = std::chrono::high_resolution_clock::now();
        int length = v.size()/2;
        double value = 0;
        for(int i = 0; i < length; ++i){
            value = map.at(v[i]);
        }
    auto stop_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> map_benchmark_duration = stop_time - start_time;
    std::cout << "map access benchmark with at() function: " << map_benchmark_duration.count() << std::endl;
    std::cout<<std::endl;
}

void benchamark_umap_find_element(std::unordered_map<int,double> &umap, std::vector<int>&v){
    auto start_time = std::chrono::high_resolution_clock::now();
        int length = v.size()/2;
        double value = 0;
        for(int i = 0; i < length; ++i){
            value = umap.at(v[i]);
        }
    auto stop_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> umap_benchmark_duration = stop_time - start_time;
    std::cout << "umap access benchmark with at() function: " << umap_benchmark_duration.count() << std::endl;
    std::cout<<std::endl;
}

void benchmark_map_access(std::map<int,double>&m, std::vector<int>&v){
    auto start_time = std::chrono::high_resolution_clock::now();
        int length = v.size()/2;
        double value = 0;
        for(int i = 0; i < length; ++i){
            value = m[v[i]];
        }
    auto stop_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> map_benchmark_duration = stop_time - start_time;
    std::cout << "map access benchmark with operator[]: " << map_benchmark_duration.count() << std::endl;
    std::cout<<std::endl;
}

void benchmark_umap_access(std::unordered_map<int,double>&um, std::vector<int>&v){
    auto start_time = std::chrono::high_resolution_clock::now();
        int length = v.size()/2;
        double value = 0;
        for(int i = 0; i < length; ++i){
            value = um[v[i]];
        }
    auto stop_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> umap_benchmark_duration = stop_time - start_time;
    std::cout << "umap access benchmark with operator[]: " << umap_benchmark_duration.count() << std::endl;
    std::cout<<std::endl;
}

int main() {
    std::map<int, double> map;
    std::unordered_map<int, double> umap;
    std::vector<int> keys;
    for (int i = 0; i < 1024 * 1024; ++i) {
        int random_number = rand();
        keys.push_back(random_number);
        map[random_number] = (double)rand() / RAND_MAX;
        umap[random_number] = (double)rand() / RAND_MAX;
    }


    
    benchamark_map_insert(map);
    benchamark_unordered_map_insert(umap);  

    benchamark_map_find_element(map, keys);  
    benchamark_umap_find_element(umap,keys);
    std::cout << std::endl;
    benchmark_map_access(map,keys);
    benchmark_umap_access(umap, keys);
    
    return 0;
}

/***********************************************
insert results (inserting 1000 pairs)

map benchmark: 1.2174
umap benchmark: 0.3599

unordered_map is faster because map has to sort elements and unordered_map has not.

finding element in container result: 

for 1024 requests

/////////// measurement /////////////
map access benchmark with at() function: 0.91
umap access benchmark with at() function: 0.1193

map access benchmark with operator[]: 1.2359
umap access benchmark with operator[]: 0.1834
//////////////////////////////////////

for 1024*1024/2 requests

///////////// measurement /////////////
map access benchmark with at() function: 466.373
umap access benchmark with at() function: 54.5819

map access benchmark with operator[]: 638.078
umap access benchmark with operator[]: 62.0935
//////////////////////////////////////
*********************************************/

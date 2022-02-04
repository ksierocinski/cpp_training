
#include <cstdlib>
#include <iostream>
#include <map>
#include <unordered_map>

/*****************************************************************************
 * std::map<Key, T>::insert
 * std::unordered_map<Key, T>::insert
 * 
 * Benchmark inserting element to the map and unordered_map.
 * 
 * Analize the results. What can you say about the complexity?
 * 
 ****************************************************************************/ 

void benchamark_map_insert(std::map<int, double>& map)
{

}

void benchamark_unordered_map_insert(std::unordered_map<int, double>& umap)
{
    
}

int main() {
    std::map<int, double> map;
    std::unordered_map<int, double> umap;

    for (int i = 0; i < 1024 * 1024; ++i) {
        map[rand()] = (double)rand() / RAND_MAX;
        umap[rand()] = (double)rand() / RAND_MAX;
    }

    benchamark_map_insert(map);
    benchamark_unordered_map_insert(umap);    
    
    return 0;
}

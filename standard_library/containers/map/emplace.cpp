#include <cstdlib>
#include <iostream>
#include <map>
#include <unordered_map>


/*****************************************************************************
 * std::map<Key, T>::emplace
 * std::unordered_map<Key, T>::emplace
 * 
 * Benchmark emplace elements to the map and unordered_map.
 * (modify existing code if needed)
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
    std::unordered_map<int,double> umap;


   // benchamark_map_insert(map);
   // benchamark_unordered_map_insert(umap); 

    return 0;
}

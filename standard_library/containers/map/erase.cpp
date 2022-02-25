#include <iostream>
#include <map>
#include <unordered_map>

/*****************************************************************************
 * std::map<Key, T>::erase
 * Benchmark erasing elements from map and unordered_map
 * 
 ****************************************************************************/ 

void erase_single_element_map(std::map<int,int> &map){

}

void erase_single_element_umap(std::unordered_map<int,int> &map){
    
}

void erase_range_of_elements_map(std::map<int,int> &map){

}

void erase_range_of_elements_umap(std::unordered_map<int,int> &map){

}

int main() {

    std::map<int,int> map;
    std::unordered_map<int,int> umap;

    for (int i = 0; i < 1024*1024; ++i) {
        map[rand()] = rand();
        umap[rand()] = rand();
    }

    erase_single_element_map(map);
    erase_single_element_umap(umap);
    erase_range_of_elements_map(map);
    erase_range_of_elements_umap(umap);

    return 0;
}

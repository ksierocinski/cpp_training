#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
#include <cstdlib>
#include <chrono>

/*****************************************************************************
 * std::map<Key, T>::operator[]
 * std::unordered_map<Key, T>::operator[]
 * 
 * Benchmark accessing element to the map and unordered_map.
 * 
 * Analize the results. What can you say about the complexity?
 * 
 ****************************************************************************/ 

class Key{
    public:
        int x;
        int y;
};

class KeyCmp{
    public:
        bool operator()(const Key &lhs, const Key &rhs)const{
            if(lhs.x == rhs.x){
                return lhs.y < rhs.y;
            }
            return lhs.x < rhs.x;
        }
};

class KeyHash {
    public:
        std::size_t operator()(const Key& k) const
        {
            return std::hash<int>()(k.x) ^ (std::hash<int>()(k.y) << 1);
        }
};
 
class KeyEqual {
    public:
        bool operator()(const Key& lhs, const Key& rhs) const
        {
            return lhs.x == rhs.x && lhs.y == rhs.y;
        }
};

void benchmark_map_access(std::map<Key,double,KeyCmp>&m, std::vector<std::pair<int,int>>&v){
    auto start_time = std::chrono::high_resolution_clock::now();
        int length = v.size()/2;
        double value = 0;
        for(int i = 0; i < length; ++i){
            value = m[{v[i].first,v[i].second}];
        }
    auto stop_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> map_benchmark_duration = stop_time - start_time;
    std::cout << "map access benchmark with operator[]: " << map_benchmark_duration.count() << std::endl;
    std::cout<<std::endl;
}

void benchmark_umap_access(std::unordered_map<Key,double,KeyHash, KeyEqual>&um, std::vector<std::pair<int,int>>&v){
    auto start_time = std::chrono::high_resolution_clock::now();
        int length = v.size()/2;
        double value = 0;
        for(int i = 0; i < length; ++i){
            value = um[{v[i].first,v[i].second}];
        }
    auto stop_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> umap_benchmark_duration = stop_time - start_time;
    std::cout << "umap access benchmark with operator[]: " << umap_benchmark_duration.count() << std::endl;
    std::cout<<std::endl;
}

void benchmark_map_access_at(std::map<Key,double,KeyCmp>& m, std::vector<std::pair<int,int>>&v){
    auto start_time = std::chrono::high_resolution_clock::now();
    int length = v.size()/2;
    double value = 0;
    for(int i = 0 ; i <length ; ++i){
        value = m.at({v[i].first,v[i].second});
    }
    auto stop_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double,std::milli> map_benchmark_duration_at = stop_time - start_time;
    std::cout << "map access benchmark with at() function: " << map_benchmark_duration_at.count() << std::endl;
    std::cout << std::endl;
}

void benchmark_umap_access_at(std::unordered_map<Key,double,KeyHash,KeyEqual>&um, std::vector<std::pair<int,int>>&v){
    auto start_time = std::chrono::high_resolution_clock::now();
    int length = v.size()/2;
    double value = 0;
    for(int i = 0; i < length; ++i){
        value = um.at({v[i].first,v[i].second});
    }
    auto stop_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double,std::milli> umap_benchmark_duration_at = stop_time - start_time;
    std::cout << "umap access benchmark with at() function: " << umap_benchmark_duration_at.count() << std::endl;
    std::cout << std::endl;
}

int main() {
    std::vector<std::pair<int,int>> vect;
    std::map<Key,double,KeyCmp> map;
    std::unordered_map<Key, double, KeyHash, KeyEqual> umap;

    for (int i = 0; i < 1024 * 1024; ++i){
        std::pair<int,int> random_number = {rand(),rand()};
        vect.push_back(random_number);
        map[{random_number.first, random_number.second}] = (double)rand()/RAND_MAX;
        umap[{random_number.first, random_number.second}] = (double)rand()/RAND_MAX;
        
    }

    benchmark_map_access(map,vect);
    benchmark_umap_access(umap,vect);
    std::cout << std::endl;
    benchmark_map_access_at(map,vect);
    benchmark_umap_access_at(umap,vect);
    // std::cout << umap[{vect[4].first,vect[4].second}] << std::endl;

    return 0;
}

/***************************************************
for 1024*1024/2 requests
///////////// mesasurement //////////////////
map access benchmark with operator[]: 458.902
umap access benchmark with operator[]: 81.3618

map access benchmark with at() function: 525.681
umap access benchmark with at() function: 61.2331
//////////////////////////////////////
****************************************************/
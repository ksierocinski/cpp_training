#include <iostream>
#include <map>

/*****************************************************************************
 * std::map<Key, T>::size
 * Check size of given maps
 * 
 ****************************************************************************/ 

int main() {
    std::map<int,int> m1 {{1,1},{2,2},{3,3},{4,4}};
    std::map<int,int> m2 = m1;
    std::map<int,int> m3;

    for(int i = 0; i < 100; ++i){
        m3[rand()] = rand();
    }
    
    return 0;
}

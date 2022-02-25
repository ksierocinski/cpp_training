#include <iostream>
#include <map>

/*****************************************************************************
 * std::map<Key, T>::operator==
 * Check if given maps are equal or not. Print results
 * 
 ****************************************************************************/ 

int main() {

    std::map<int,int> m1 {{1,1},{2,2},{3,3},{4,4},{5,5}};
    std::map<int,int> m2 {{1,1},{2,2},{3,3},{4,4},{5,5}};
    std::map<int,int> v3 {{2,2},{13,13},{6,6},{11,11},{25,25}};
    std::map<int,int> v4 {{1,1},{2,2},{3,3}};

    //is m1 equal to m2?

    //is m1 equal to m3?
    
    //is m1 equal to m4?

    //is m2 equal to m3?

    //is m2 equal to m4?
    
    //is m3 equal to m4?

    return 0;
}

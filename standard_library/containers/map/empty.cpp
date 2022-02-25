#include <iostream>
#include <map>

/*****************************************************************************
 * std::map<Key, T>::empty
 * Check if maps are empty or not - print results.
 * 
 ****************************************************************************/ 

int main() {
    std::map<int,int> m1 {{1,1}, {2,2}, {3,3}}, m2, m3{};
    m2 = m1;
    return 0;
}

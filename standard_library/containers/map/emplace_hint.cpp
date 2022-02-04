#include <iostream>
#include <map>
#include <unordered_map>

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

int main() {
    return 0;
}

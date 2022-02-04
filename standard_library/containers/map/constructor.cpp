#include <iostream>
#include <map>
#include <unordered_map>

/*****************************************************************************
 * std::map<Key, T>::map
 * std::unordered_map<Key, T>::unordered_map
 * 
 * Test constructors:
 * std::map<std::string, double>
 * std::unordered_map<std::string, double>
 * std::map<Key, double>
 * std::unordered_map<Key, double>
 * 
 * 
 * What can you say about the constuctors? Why std::unordered_map<Key, double>
 * didn't work? Change Key class to make it possible to be a key in the
 * unordered map.
 ****************************************************************************/ 

class Key {
    int x;
    int y;
};

int main() {
    
    return 0;
}

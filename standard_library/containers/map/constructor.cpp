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
    public:
        int x;
        int y;
};

class KeyCmp {
    public:
    bool operator()(const Key& lhs, const Key& rhs) const { 
        if(lhs.x == rhs.x){
            return lhs.y < rhs.y;
        }
        return lhs.x < rhs.x;
    };
};

template<class Map>
void print_map(Map &m){
    for(auto it = m.begin(); it != m.end(); ++it){
        std::cout << it -> first << " : " << it -> second << std::endl;
    }
    std::cout << std::endl;
}

template<class Map>
void print_custom_key_map(Map &m){
    for(auto it = m.begin(); it != m.end(); ++it){
        std::cout << "{" << it -> first.x << "," << it -> first.y << "}"  << " : " << it -> second<< std::endl;
    }
    std::cout<<std::endl;
}

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
 

int main() {
    std::map<std::string, double> container1 {
        {"key1", 1.4},
        {"key2", 23.6},
        {"key3", 6.2},
        {"key4", 6.4},
        {"key5", 1.7}
    };
    std::cout << "std::map<std::string, double>" << std::endl;
    print_map(container1);


    std::unordered_map<std::string, double> container2 {
        {"key6", 1.4},
        {"key7", 23.6},
        {"key8", 6.2},
        {"key9", 6.4},
        {"key10", 1.7}
    };
    std::cout << "std::unordered_map<std::string, double>" << std::endl;
    print_map(container2);



    std::map<Key, double, KeyCmp> container3 = {
        {{1,1}, 1.4},
        {{1,2}, 23.6},
        {{1,3}, 6.2},
        {{1,4}, 6.4},
        {{1,5}, 1.7}
    };
    std::cout << "std::map<Key, double>" << std::endl;
    print_custom_key_map(container3);


    std::unordered_map<Key, double, KeyHash, KeyEqual> container4 = {
        {{2,1}, 1.4},
        {{2,2}, 23.6},
        {{2,3}, 6.2},
        {{2,4}, 6.4},
        {{2,5}, 1.7}
    };
    std::cout << "std::unordered_map<Key, double>" << std::endl;
    print_custom_key_map(container4);

    // std::unordered_map<Key, double> container4 = {
    //     {{2,1}, 1.4},
    //     {{2,2}, 23.6},
    //     {{2,3}, 6.2},
    //     {{2,4}, 6.4},
    //     {{2,5}, 1.7}
    // };

    return 0;
}

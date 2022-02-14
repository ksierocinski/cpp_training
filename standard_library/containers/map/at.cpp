#include <iostream>
#include <map>

/*****************************************************************************
 * std::map<Key, T>::at
 * 
 * Write and test the function that prints whole map.
 * 
 * Try to use [] operator. Why did it failed?
 ****************************************************************************/ 

template<class Key, class T>
void print_fisrt_and_last(const std::map<Key, T>& v)
{
    
    // for(auto it = v.begin(); it != v.end(); it++){
    //     std::cout << it->first << " : " << (*it).second << std::endl;
    // }

    // for(auto el: v){
    //     std::cout << el.first << " : " << el.second << std::endl;
    // }

    for(auto el : v){
        std::cout << el.first << " : " << v.at(el.first) << std::endl;
        // std::cout <<el.first << " : " <<  v[el.first] << std::endl; // operator[] doesn't work in this case, because operator[] is non-const, because if element doesn't exist in map , operator[] insert key to this container
    }
}

int main() {
    std::map<std::string,int> container{
        {"this", 100},
        {"can", 100},
        {"be", 100},
        {"const", 100}
    };
    print_fisrt_and_last<std::string,int>(container);
    return 0;
}

/****************************************
results
be : 100
can : 100
const : 100
this : 100
***************************************/

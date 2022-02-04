#include <iostream>
#include <vector>

/*****************************************************************************
 * std::vector<T,Allocator>::push_back
 * 
 * Test std::vector<T>::push_back.
 * 
 * Add several elements, check how the size and capasity are changing.
 *  
 ****************************************************************************/ 

int main() {
    std::vector<int> numbers;
    std::cout << "Size of vector: " <<  numbers.size() << " | " << "Capacity: " << numbers.capacity() << std::endl;
    for(int i = 0; i < 20;i++){
        numbers.push_back(i);
        std::cout << "Size of vector: " <<  numbers.size() << " | " << "Capacity: " << numbers.capacity() << std::endl;

    }
    return 0;
}
/***********************************************
Results
Size of vector: 0 | Capacity: 0
Size of vector: 1 | Capacity: 1
Size of vector: 2 | Capacity: 2
Size of vector: 3 | Capacity: 4
Size of vector: 4 | Capacity: 4
Size of vector: 5 | Capacity: 8
Size of vector: 6 | Capacity: 8
Size of vector: 7 | Capacity: 8
Size of vector: 8 | Capacity: 8
Size of vector: 9 | Capacity: 16
Size of vector: 10 | Capacity: 16
Size of vector: 11 | Capacity: 16
Size of vector: 12 | Capacity: 16
Size of vector: 13 | Capacity: 16
Size of vector: 14 | Capacity: 16
Size of vector: 15 | Capacity: 16
Size of vector: 16 | Capacity: 16
Size of vector: 17 | Capacity: 32
Size of vector: 18 | Capacity: 32
Size of vector: 19 | Capacity: 32
Size of vector: 20 | Capacity: 32
***************************************/

#include <iostream>
#include <vector>

/*****************************************************************************
 * std::vector<T,Allocator>::data
 * 
 * Write and test a function that casts vector to C array.
 * 
 ****************************************************************************/ 

template<class T>
T* cast_to_C_array(std::vector<T> &v)
{
    return v.data();
}

int main() {
    std::vector<int> numbers_vector{2,6,4,98,3,7,3,8};
    int* arr = cast_to_C_array<int>(numbers_vector);
    for(int i = 0; i < numbers_vector.size(); i++){
        std::cout << "Vector "<< i <<" element: " << numbers_vector[i] << std::endl;
        std::cout << "Array "<< i <<" element: " << arr[i] << std::endl;
    }
    return 0;
}

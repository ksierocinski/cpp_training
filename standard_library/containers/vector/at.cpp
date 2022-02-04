#include <iostream>
#include <vector>

/*****************************************************************************
 * std::vector<T,Allocator>::at
 * 
 * Write and test the function that prints first and last element from the
 * vector.
 * 
 * Try to use [] operator. Why did it failed?
 ****************************************************************************/ 

template<class T>
void print_fisrt_and_last(const std::vector<T>& v)
{
    std::cout << "First element (at): " << v.at(0) << std::endl;
    std::cout << "Last element (at): " << v.at(v.size()-1) << std::endl << std::endl;
    std::cout << "First element (op[]): " << v[0] << std::endl;
    std::cout << "Last element (op[]): " << v[v.size()-1] << std::endl;

}

int main() {
    std::vector<int> container {3,7,3,5,67,9,4,6};
    print_fisrt_and_last<int>(container);
    return 0;
}

/***********************************************
Result:
First element (at): 3
Last element (at): 6
First element (op[]): 3
Last element (op[]): 6
**************************************/
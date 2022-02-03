#include <iostream>
#include <vector>

/*****************************************************************************
 * std::vector<T,Allocator>::vector
 * 
 * Test constructors:
 * std::vector<T>(value)
 * std::vector<T>{value}
 * std::vector<T>(value, value)
 * std::vector<T>{value, value}
 * 
 * For each one see what is the: size and elements values.
 * 
 * What can you say about the constuctors? Why they work like that?
 ****************************************************************************/ 
void print_info(const std::vector<int>& container, const std::string& name){
    std::cout << "Values in " << name << " vector: " << std::endl;
    for(int el:container){
        std::cout << el << std::endl;
    }
    std::cout<< "Size of " << name << " vector: " << container.size()<<std::endl << std::endl;
}

int main() {
    std::vector<int>first(5);
    std::vector<int>second {5};
    std::vector<int>third(5,2);
    std::vector<int>fourth {5,4};

    print_info(first, "first");
    print_info(second, "second");
    print_info(third, "third");
    print_info(fourth, "fourth");
    
    return 0;
}

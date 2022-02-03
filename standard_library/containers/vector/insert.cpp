#include <iostream>
#include <vector>

/*****************************************************************************
 * std::vector<T,Allocator>::insert
 * 
 * Benchmark inserting element to the vector.
 * 
 * Analize the results.
 * 
 ****************************************************************************/ 

void benchamark_insert_front(std::vector<double>& v)
{

}

void benchamark_insert_middle(std::vector<double>& v)
{
    
}

void benchamark_insert_end(std::vector<double>& v)
{
    
}


int main() {
    std::vector<double> v(1024*1024 + 1);
    
    benchamark_insert_front(v);

    benchamark_insert_middle(v);

    benchamark_insert_end(v);
    
    return 0;
}

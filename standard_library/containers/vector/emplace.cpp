#include <iostream>
#include <vector>

/*****************************************************************************
 * std::vector<T,Allocator>::emplace
 * Benchmark inserting elements into vector using emplace.
 * There will be to cases: adding elements to the end of vector ande adding elements somewhere in the middle
 * Analize the results.
 ****************************************************************************/ 

void emplace_end_benchmark(std::vector<int> &v){

}

void emplace_mid_benchmark(std::vector<int> &v){

}

int main() {
    std::vector<int> numbers(20,4);

    emplace_end_benchmark(numbers);
    emplace_mid_benchmark(numbers);

    return 0;
}

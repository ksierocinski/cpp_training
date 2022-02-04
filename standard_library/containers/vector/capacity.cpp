#include <iostream>
#include <vector>

/*****************************************************************************
 * std::vector<T,Allocator>::capacity
 * 
 * One by one ddd 33 elements to the vector. Each time check vector size and
 * capacity.
 * 
 ****************************************************************************/ 

int main() {
    std::vector<int> numbers;
    for(int i = 0; i < 33; i++){
        std::cout << i << ". Size: " << numbers.size() << "| Capacity: " << numbers.capacity() << std::endl;
        numbers.push_back(i);
    }
    return 0;
}

/*********************************************************************************************
Result:
0. Size: 0| Capacity: 0
1. Size: 1| Capacity: 1
2. Size: 2| Capacity: 2
3. Size: 3| Capacity: 4
4. Size: 4| Capacity: 4
5. Size: 5| Capacity: 8
6. Size: 6| Capacity: 8
7. Size: 7| Capacity: 8
8. Size: 8| Capacity: 8
9. Size: 9| Capacity: 16
10. Size: 10| Capacity: 16
11. Size: 11| Capacity: 16
12. Size: 12| Capacity: 16
13. Size: 13| Capacity: 16
14. Size: 14| Capacity: 16
15. Size: 15| Capacity: 16
16. Size: 16| Capacity: 16
17. Size: 17| Capacity: 32
18. Size: 18| Capacity: 32
19. Size: 19| Capacity: 32
20. Size: 20| Capacity: 32
21. Size: 21| Capacity: 32
22. Size: 22| Capacity: 32
23. Size: 23| Capacity: 32
24. Size: 24| Capacity: 32
25. Size: 25| Capacity: 32
26. Size: 26| Capacity: 32
27. Size: 27| Capacity: 32
28. Size: 28| Capacity: 32
29. Size: 29| Capacity: 32
30. Size: 30| Capacity: 32
31. Size: 31| Capacity: 32
32. Size: 32| Capacity: 32
**************************************************************************************************/

#include <iostream>
#include <vector>

#include "QuickSort.h"

int main()
{
    constexpr size_t arraySize = 6;
    int array[arraySize] = {4, 9, 2, 7, 3, 7};

    for (auto i : array)
        std::cout << i << " ";
    std::cout << "\n";

    Custom::sort(array, array + arraySize);

    for (auto i : array)
        std::cout << i << " ";
    std::cout << "\n";

    std::vector<int> v(array, array + arraySize);

    Custom::sort(v.begin(), v.end());

    for (auto i : v)
        std::cout << i << " ";
    std::cout << "\n";

    return 0;
}

#pragma once

#include <iterator>
#include <stdlib.h>
#include <chrono>
#include <algorithm>

namespace Custom {

template <typename RandomIteratorType>
void sort(RandomIteratorType first, RandomIteratorType last)
{
    using ValueType = typename std::remove_reference<decltype(*first)>::type;

    size_t distance = std::distance(first, last);

    if (distance < 2)
        return;

    if (distance == 2) {
        if (*first > *(first + 1))
            std::swap(*first, *(first + 1));

        return;
    }

    std::srand(std::time(0));
    RandomIteratorType pPivot = first + std::rand() % distance;

    auto pivot = *pPivot;

    auto arrayCopy = new ValueType[distance];
    auto front = arrayCopy;
    auto back = arrayCopy + distance;

    size_t pivotCounter{};

    for (auto it = first; it != last; ++it) {
        auto value = *it;
        if (value < pivot)
            *(front++) = value;
        else if (value > pivot)
            *(--back) = value;
        else
            ++pivotCounter;
    }

    for (auto it = front; it != front + pivotCounter; ++it)
        *it = pivot;

    std::copy(arrayCopy, arrayCopy + distance, first);

    delete[] arrayCopy;

    pPivot = std::find(first, last, pivot);

    Custom::sort(first, pPivot);
    Custom::sort(pPivot + 1, last);
}

} // namespace Custom

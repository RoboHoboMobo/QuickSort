#pragma once

#include <iterator>
#include <algorithm>

namespace Custom {

// QuickSort for C++11

template <typename RandomIteratorType, typename Compare>
void sort(RandomIteratorType first, RandomIteratorType last, Compare comp)
{
    using ValueType = typename std::remove_reference<decltype(*first)>::type;

    if (first == last)
        return;

    RandomIteratorType pPivot = first + std::distance(first, last) / 2;

    auto pivot = *pPivot;

    auto left = std::partition(first, last, [&pivot, comp](const ValueType& element) {
            return comp(element, pivot);
    });

    auto right = std::partition(left, last, [&pivot, comp](const ValueType& element) {
        return !comp(pivot, element);
    });

    Custom::sort(first, left, comp);
    Custom::sort(right, last, comp);
}

template <typename RandomIteratorType>
void sort(RandomIteratorType first, RandomIteratorType last)
{    
    using ValueType = typename std::remove_reference<decltype(*first)>::type;

    if (first == last)
        return;

    RandomIteratorType pPivot = first + std::distance(first, last) / 2;

    auto pivot = *pPivot;

    auto left = std::partition(first, last, [&pivot](const ValueType& element) {
            return element < pivot;
    });

    auto right = std::partition(left, last, [&pivot](const ValueType& element) {
        return !(pivot < element);
    });

    Custom::sort(first, left);
    Custom::sort(right, last);
}

} // namespace Custom

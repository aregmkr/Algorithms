#include <iostream>
#include <algorithm>
#include <vector>

std::vector<int> counting_sort(std::vector<int> arr) {
    auto min = *std::min_element(arr.begin(), arr.end());
    auto max = *std::max_element(arr.begin(), arr.end());
    const int size = arr.size();
    const int range = max - min + 1;
    std::vector<int> output(size);
    std::vector<int> count(range, 0);
    for (int i = 0; i < size; ++i) {
        ++count[arr[i] - min];
    }

    for (int i = 1; i < range; ++i) {
        count[i] += count[i - 1];
    }

    for (int i = size - 1; i >= 0; --i) {
        output[--count[arr[i]] - min] = arr[i];
    }

    return output;
}
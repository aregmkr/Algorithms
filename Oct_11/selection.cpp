#include <iostream>
#include <vector>

std::vector<int> selection_sort(std::vector<int>& arr) {
    const int size = arr.size();

    for (int i = 0; i < size - 1; ++i) {
        int index = i;
        for (int j = i + 1; j < size; ++j) {
            if (arr[j] < arr[index]) {
                index = j;
            }
        }
    if (index != i) {
        int tmp = arr[index];
        arr[index] = arr[i];
        arr[i] = tmp;
    }
    }
    return arr;
}
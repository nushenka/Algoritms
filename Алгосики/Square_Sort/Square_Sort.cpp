#include <algorithm>
#include <iostream>

void Sort(int* start, int* end) {
    for (int* i = start + 1; i < end; ++i) {
        int* j = i;
        while (j > start && *(j - 1) > *j) {
            std::swap(*j, *(j - 1));
            --j;
        }
    }
}

int main() {
    int n = 0;
    std::cin >> n;
    int* array = new int[n];
    for (int i = 0; i < n; ++i) {
        std::cin >> array[i];
    }
    Sort(array, array + n);
    for (int i = 0; i < n; ++i) {
        std::cout << array[i] << " ";
    }
    delete[] array;
    return 0;
}
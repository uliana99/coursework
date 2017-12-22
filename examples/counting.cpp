//  EXAMPLE_COUNTING.CPP

#include "counting.hpp"

//! [counting_sort_example]

void sortCounting() {
    srand(time(NULL));
    const int ARRAY_LEN = 40;
    const int INT_RANGE = 1000;
    int *array = new int[ARRAY_LEN];

    for (int i = 0; i < ARRAY_LEN; i++) {
        array[i] = rand() % INT_RANGE;
    }

    message(array, ARRAY_LEN);
    counting_sort(array, ARRAY_LEN, INT_RANGE);
    message(array, ARRAY_LEN);
}

//! [counting_sort_example]

int main(int argc, char const *argv[]) {
    sortCounting();
    return 0;
}

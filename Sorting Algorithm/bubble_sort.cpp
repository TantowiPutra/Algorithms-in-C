#include <iostream>
using namespace std;

void BubbleSort(int *arr, int size) {
    // First Iteration
    // i = 0
    // j = 1  - 3 8 1 2 3 10 // arr[0] > arr[1] ? NO
    // j = 2  - 3 8 1 2 3 10 // arr[0] > arr[2] ? YES, SWAP
    // j = 3  - 1 8 3 2 3 10 // arr[0] > arr[3] ? NO
    // j = 4  - 1 8 3 2 3 10 // arr[0] > arr[4] ? NO
    // j = 5  - 1 8 3 2 3 10 // arr[0] > arr[5] ? NO

    // Second Iteration
    // i = 1
    // j = 2  - 1 8 3 2 3 10 // arr[1] > arr[2] ? YES, SWAP
    // j = 3  - 1 3 8 2 3 10 // arr[1] > arr[3] ? YES, SWAP
    // j = 4  - 1 2 8 3 3 10 // arr[1] > arr[4] ? NO
    // j = 5  - 1 2 8 3 3 10 // arr[1] > arr[5] ? NO

    // Third Iteration
    // i = 2
    // j = 3  - 1 2 8 3 3 10 // arr[2] > arr[3] ? YES, SWAP
    // j = 4  - 1 2 3 8 3 10 // arr[2] > arr[4] ? NO
    // j = 5  - 1 2 3 8 3 10 // arr[2] > arr[5] ? NO

    // Fourth Iteration
    // i = 3
    // j = 4  - 1 2 3 8 3 10 // arr[3] > arr[4] ? YES, SWAP
    // j = 5  - 1 2 3 3 8 10 // arr[3] > arr[5] ? NO

    // Result: 1 2 3 3 8 10
    // If nothing swapped, mark as already sorted

    bool flag_sorted = false;
    for(int i = 0; i < size && !flag_sorted; i++) {
        // j = i + 1, doesn't need to compare to current index
        flag_sorted = true;

        for(int j = i + 1; j < size ; j++) {
            if(arr[i] > arr[j]) {
                // Swap Value without using temp variable
                arr[i] = arr[i] + arr[j];

                arr[j] = arr[i] - arr[j];
                arr[i] = arr[i] - arr[j];

                flag_sorted = false;
            }
        }

        // Stop when nothing is swapped
        if(flag_sorted) break;
    }
}

void PrintArray(int *arr, int size) {
    for(int i = 0; i < size ; i++) {
        cout << arr[i] << " ";
    }
}

int main() { 
    int number[] = {3, 8, 1 ,2, 3, 10};
    int size     = sizeof(number) / sizeof(number[0]);

    BubbleSort(number, size);
    PrintArray(number, size);

    return 0;
}
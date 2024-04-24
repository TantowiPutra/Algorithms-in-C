#include <iostream>
using namespace std;

// This function return the array index of the specified target value, if not found, return -1
int BinarySearch(int *arr, int low, int high, int target) {
    while(high >= low) {
        int mid = low + ((high - low) / 2);

        if(arr[mid] == target) {
            // if target value is found
            return mid;
        } else if(arr[mid] > target) {
            // if target is still greater than mid, then focus on the left half of the array
            return BinarySearch(arr, low, mid - 1, target);
        } else if(arr[mid] < target) {
            // if target is still greater than mid, then focus on the right half of the array
            return BinarySearch(arr, mid + 1, high, target);
        }
    }

    return -1;
}

int main() {
    int number[] = {10, 11, 12, 13, 14, 15, 16, 17, 18, 19};

    int result = BinarySearch(number, 0, sizeof(number) / sizeof(number[0]), 10);
    cout << "Value 10 is located at index: " << result << endl;

    result = BinarySearch(number, 0, sizeof(number) / sizeof(number[0]), 13);
    cout << "Value 13 is located at index: " << result << endl;

    result = BinarySearch(number, 0, sizeof(number) / sizeof(number[0]), 14);
    cout << "Value 14 is located at index: " << result << endl;

    return 0;
}
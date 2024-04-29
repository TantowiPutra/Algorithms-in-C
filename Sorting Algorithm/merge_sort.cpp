// Example Merge
// {3, 7, 8, 5, 4, 2, 6, 1}

#include <iostream>
using namespace std;

void merge(int *arr, int left, int mid, int right) {

}

void mergeSort(int *numbers, int left, int right) {
    // Kalo kiri >= kanan, berarti sudah sampai base case, gaperlu pecah jadi array lagi
    if(left >= right) return;

    int mid = left + (right - left) / 2;
    cout << left << " " << mid << " " << right << endl;

    // Kiri
    mergeSort(numbers, left, mid);

    // Kanan
    mergeSort(numbers, mid + 1, right);

    // Pecah array recursively, terus jadiin satu ketika tree sudah sampai node paling ujung
    merge(numbers, left, mid, right);
}

void PrintArray(int *arr, int size) {
    for(int i = 0; i < size ; i++) {
        cout << arr[i] << " ";
    }
}

int main() {
    int numbers[8] = {3, 7, 8, 5, 4, 2, 6, 1};
    int arrSize = sizeof(numbers) / sizeof(numbers[0]);

    mergeSort(numbers, 0, arrSize - 1); 

    return 0;
}
// Example Merge
// {3, 7, 8, 5, 4, 2, 6, 1}

#include <iostream>
using namespace std;

void merge(int *array, int left, int mid, int right) {
    
    /*
        Misal: array{1, 3, 4, 5, 5}
        left: 0
        mid: 2
        right: 4

        buat sub array, berarti sizenya 5
        kiri    : selisih (mid - left +1)
        kanan   : selisih (kanan - mid)

        kalo ditotal kiri + kanan bakal jadi 5
    */

    auto const sizeSubArrOne = mid - left + 1;
    auto const sizeSubArrTwo = right - mid;

}

void mergeSort(int *numbers, int left, int right, string currNode) {
    // if(currNode == "left") {
    //     cout << "left: " << left << " " << mid << " " << right << endl;
    // } else  if(currNode == "right") {
    //     cout << "right: " << left << " " << mid << " " << right << endl;
    // } else {
    //     cout << "root: " << left << " " << mid << " " << right << endl;
    // }

    // Kalo kiri >= kanan, berarti sudah sampai base case, gaperlu pecah jadi array lagi
    if(left >= right) return;

    int mid = left + (right - left) / 2;

    // cout << left << " " << mid << " " << right << endl; 

    // ! Visualize the process as binary tree to understand the concept
    // Kiri
    mergeSort(numbers, left, mid, "left");

    // Kanan
    mergeSort(numbers, mid + 1, right, "right");

    // cout << "Call Merge" << endl; 

    // Pecah array recursively, terus jadiin satu ketika tree sudah sampai node paling ujung
    // cout << "Call Merge" << endl; 
    merge(numbers, left, mid, right);
}

void PrintArray(int *arr, int size) {
    for(int i = 0; i < size ; i++) {
        cout << arr[i] << " ";
    }
}

int main() {
    int numbers[5] = {3, 1, 2, 4, 5};

    int arrSize = sizeof(numbers) / sizeof(numbers[0]);

    mergeSort(numbers, 0, arrSize - 1, "root"); 

    // PrintArray(numbers, arrSize); 

    return 0;
}
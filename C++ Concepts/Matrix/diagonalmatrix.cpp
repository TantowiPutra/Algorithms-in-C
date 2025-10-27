#include <bits/stdc++.h>

void printArr(int *arr, int size) {
    for(int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int m[5][5] = {
        {3, 0, 0, 0, 0},
        {0, 7, 0, 0, 0},
        {0, 0, 4, 0, 0},
        {0, 0, 0, 9, 0},
        {0, 0, 0, 0, 6}
    };

    int A[5]= {0, 0, 0, 0, 0};

    for(int i = 0, j = 0; i < 5; i++, j++) {
        A[i] = m[i][j];
    }


    printArr(A, 5);
 
    return 0;
}
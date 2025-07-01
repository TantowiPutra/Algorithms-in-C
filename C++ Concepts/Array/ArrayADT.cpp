#include <iostream>
#include <stdlib.h>

struct Array {
    int *A;
    int size;
    int length;
};

void Display(struct Array arr)
{
    int i;
    printf("\nElements Array: \n");
    for(i = 0; i < arr.length; i++) 
        printf("%d ", arr.A[i]);

    // DISPLAY O(n)
} 

void Append(struct Array *arr, int x)
{
    if(arr->length < arr->size) {
        arr->A[arr->length] = x;
        arr->length += 1;
    }

    // APPEND O(1)
}

void Insert(struct Array *arr, int idx, int x) {
    // 1 2 3 4 5 6 7 8 9 10
    if(arr->length < arr->size && idx <= arr->length) {
        for(int i = arr->length; i > idx; i--) {
            arr->A[i] = arr->A[i - 1];
        }

        arr->A[idx] = x;
        arr->length += 1;
    }

    // INSERTION O(n)
}

void Delete(struct Array *arr, int idx) {
    for(int i = idx; i < arr->length - 1; i++) {
        arr->A[i] = arr->A[i + 1];
    }

    arr->length -= 1;
}

int linearSearch(struct Array *arr, int num) {
    for(int i = 0; i < arr->length; i++) {
        if(arr->A[i] == num) {
            // TRANSPOSITION
            if(i != 0) {
                std::swap(arr->A[i], arr->A[i - 1]);
                return i - 1;
            }
            
            return i;
        }
    }

    return -1;
}

int binarySearch(struct Array *arr, int num) {
    int low = 0;
    int high = arr->length - 1;

    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(arr->A[mid] == num)
            return mid;
        else if(arr->A[mid] > num)
            high = mid - 1;
        else if(arr->A[mid] < num) {
            low = mid + 1;
        }
    }

    return - 1;
}

int main() {
    struct Array arr = {
        new int[100] {
            1, 2, 3, 4, 5, 6, 7 , 8 , 9 ,10
        },
        100,
        10
    };

    // FOR BINARY SEARCH, ARRAY MUST BE SORTED
    struct Array arr2 = {
        new int[100] {
            4, 8, 10, 15, 18, 21, 24, 27, 29, 33, 34, 37, 39, 41, 43
        },
        100,
        15
    };

    // Append(&arr, 11);
    // Display(arr);
    // std::cout << '\n' << std::endl;
    // Insert(&arr, 10, 12);
    // Display(arr);
    // std::cout << '\n' << std::endl;
    // Delete(&arr, 12);
    // Display(arr);
    // std::cout << '\n' << std::endl;

    std::cout << "Linear Search: " << linearSearch(&arr, 10) << std::endl;
    std::cout << "Binary Search: " << binarySearch(&arr2, 34) << std::endl;

    return 0;
}
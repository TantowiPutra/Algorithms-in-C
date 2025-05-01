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

int main() {
    struct Array arr = {
        new int[100] {
            1, 2, 3, 4, 5, 6, 7 , 8 , 9 ,10
        },
        100,
        10
    };
    // int n, i;

    // printf("Enter Size of an Array: ");
    // scanf("%d", &arr.size);

    // arr.A = (int *) malloc(arr.size * sizeof(int));

    // arr.length = 0;

    // printf("How Many Numbers: ");
    // scanf("%d", &n);

    // printf("Enter All Elements: ");
    // for(i = 0; i < n; i++) {
    //     scanf("%d", &arr.A[i]);
    // }

    // arr.length = n;

    Append(&arr, 11);
    Display(arr);
    std::cout << '\n' << std::endl;
    Insert(&arr, 10, 12);
    Display(arr);
    std::cout << '\n' << std::endl;

    return 0;
}
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

int Get(struct Array *arr, int idx) {
    int arrLn = arr->length;

    if(idx >= 0 && idx <= arrLn) {
        return arr->A[idx];
    } else {
        return -1;
    }
}

void Set(struct Array *arr, int val, int idx) {
    int arrLn = arr->length;
    if(idx >= 0 && idx <= arrLn) {
        arr->A[idx] = val;
    }
}

int max(struct Array *arr) {
    int max = -1;
    for(int i = 0; i < arr->length; i++) {
        max = max < arr->A[i] ? arr->A[i] : max;
    }

    return max;
}

int min(struct Array *arr) {
    int min = arr->A[0];
    for(int i = 0; i < arr->length; i++) {
        min = min > arr->A[i] ? arr->A[i] : min; 
    }

    return min;
}

int sum(struct Array *arr) {
    int sum = 0;
    for(int i = 0; i < arr->length; i++) {
        sum += arr->A[i];
    }

    return sum;
}

void reverse(struct Array *arr) {
    int temp = 0;
    int low  = 0;
    int high = arr->length - 1;

    while(low < high) {
        temp = arr->A[high];
        arr->A[high] = arr->A[low];
        arr->A[low] = temp;
        low++;
        high--;
    }
}

void leftRotate(struct Array *arr) {
    if(arr->length > 0) {
        int temp = arr->A[0];

        for(int i = 0; i < arr->length - 1; i++) {
            arr->A[i] = arr->A[i + 1];
        }

        arr->A[arr->length - 1] = temp;
    }
}

void rightRotate(struct Array *arr) {
    if(arr->length > 0) {
        int temp = arr->A[arr->length - 1];
        for(int i = arr->length - 1; i > 0; i--) {
            arr->A[i] = arr->A[i - 1];
        }

        arr->A[0] = temp;
    }
}

// INSERT A VALUE INTO A SORTED ARRAY
void insertVal(struct Array *arr, int val) {
    if(arr->length <= arr->size) {
        int length = arr->length;
        int i      = length - 1;

        // WHILE LOOP IS BETTER USED HERE, SINCE WE DON'T KNOW HOW MANY TIMES EXACTLY A LOOP WITH OCCUR
        while(i > 0 && arr->A[i] > val) {
            arr->A[i + 1] = arr->A[i];
            i--;
        }

        arr->A[i + 1] = val;
        arr->length += 1;
    }   
}

bool isArraySorted(struct Array *arr) {
    for(int i = 1; i < arr->length; i++) {
        if(arr->A[i] < arr->A[i -1]) 
            return false;
    }

    return true;
}

void minOnLeft(struct Array *arr) {
    int low = 0, high = arr->length - 1;

    while(low < high) {
        while(arr->A[low] < 0) {
            low += 1;
        }

        while(arr->A[high] > 0) {
            high -= 1;
        }

        if(low < high) {
            int temp        = arr->A[low];
            arr->A[low]     = arr->A[high];
            arr->A[high]    = temp;
        }
    }
}

int main() {
    struct Array arr = {
        new int[100] {
            11, 2, 3, 4, 5, 6, 7 , 8 , 9 ,10
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
    std::cout << "Get Array Out of Bound: "           << Get(&arr, 30) << std::endl;
    std::cout << "Get Array: "           << Get(&arr, 3) << std::endl;
    Set(&arr, 100, 2);
    std::cout << "Set Array Value: " << arr.A[2] << std::endl;
    Set(&arr, 120, 3);
    std::cout << "Set Array Value: " << arr.A[3] << std::endl;
    std::cout << "Max Array Value: " << max(&arr) << std::endl;
    std::cout << "Min Array Value: " << min(&arr) << std::endl;
    std::cout << "Sum Array Value: " << sum(&arr) << std::endl;

    std::cout << "Before Reverse: " << std::endl;
    Display(arr);
    std::cout << "\n" << std::endl;

    reverse(&arr);
    std::cout << "After Reverse: ";
    Display(arr);
    std::cout << "\n" << std::endl;

    leftRotate(&arr);
    std::cout << "After Left Rotate: ";
    Display(arr);
    std::cout << "\n" << std::endl;

    rightRotate(&arr);
    std::cout << "After Right Rotate: ";
    Display(arr);
    std::cout << "\n" << std::endl;

    struct Array srtArr = {
        new int[100] {
            4, 8, 13, 16, 20, 25, 28, 33
        },
        100,
        8
    };

    std::cout << "Orig Sorted Array: ";
    Display(srtArr);

    insertVal(&srtArr, 100);
    std::cout << "\nSorted Array After Value Insert: ";
    Display(srtArr);

    std::cout << std::endl;
    std::cout << "Is Array Sorted: " << isArraySorted(&srtArr) << std::endl;

    struct Array minOnLeftArr = {
        new int[100] {
            -6, -4, 8, -9, 10 -1, 2, 3
        },
        100,
        7
    };

    
    std::cout << std::endl;
    std::cout << "Orig Min Array Array: ";
    Display(minOnLeftArr);
    minOnLeft(&minOnLeftArr);
    std::cout << std::endl;
    std::cout << "Min On Left Array: ";
    Display(minOnLeftArr);
    
    return 0;
}
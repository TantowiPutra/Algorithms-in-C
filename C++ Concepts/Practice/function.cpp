#include <iostream>
#include <stdio.h>
using namespace std;

// This function returns the pointer to the first element of the array
int * CreateArray() {
    int *p = (int *) malloc(5 * sizeof(int));

    return p;
}

void ArrayAsParameter(int A[]) {
    for(int i = 0; i < 5; i++) {
        cout << A[i] << " ";
    }
}

int main() {
    int *a = CreateArray();
    a[0] = 1;
    a[1] = 2;
    a[2] = 3;
    a[3] = 4;
    a[4] = 5;

    for(int i = 0; i < 5; i++) {
        cout << a[i] << " ";    
    }
    
    cout << "\n";

    // =============================================================================

    ArrayAsParameter(a);

    return 0;
}
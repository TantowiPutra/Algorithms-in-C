#include <iostream>
using namespace std;

/*
    1. What is function
    2. Type of parameters
       - Pass by value
       - Pass by reference
       = Pass by pointer

*/

void PrintHalfPyramid(int &a) {
    for(int i = 0; i < a; i++) {
        for(int j = a - i - 1; j > 0; j--) {
            cout << " ";
        }

        for(int k = 0; k <= i; k++) {
            cout << "* ";
        }

        cout << "\n";
    }

}

void PrintInverseHalfPyramid(int &a) {
    for(int i = 0; i < a - 1; i++) {
        for(int j = 0; j <= i; j++) {
            cout <<  " ";
        }

        for(int k = a - 1 - i; k > 0; k--) {
            cout << "* ";
        }
        cout << "\n";
    }
}       

int main() {
    int row = 10;

    PrintHalfPyramid(row);
    PrintInverseHalfPyramid(row);

    return 0;
}
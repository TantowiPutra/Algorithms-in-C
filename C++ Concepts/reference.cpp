/*
    Heap
    Stack
    Main
    Code Solution
*/

#include <iostream>
using namespace std;

int main() {
    // Reference
    // Since it's storing reference, both variable a and r occupies the same amount of memory, which is 2 / 4 bytes depending on the operating system. a & r will also hold the same value.
    int a = 10;
    int &r = a;

    a = 20;

    cout << r << endl;

    return 0;
}
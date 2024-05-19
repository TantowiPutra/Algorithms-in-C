#include <iostream>
#include <malloc.h>
#include <memory> // Introduce in C++ >v.11

using namespace std;

/*
    Poiners are used to access data that's outside the program's scope (Heap)
    it doesn't not directly store the data, instead pointer store the address

*/

int main() {
    /*
        Assume a is taking 2 bytes of memory, which is located in the address 100 & 101

        since be is also a variable int pointer, it's also reserving 2 bytes of memory, located in the address 110 & 111
    */

    // allocate a total of 5 * the memory sizeof int, which could vary from 10 bytes (32 bit) or 20 bytes (64 bit)
    // by default, malloc returns void pointer, therefore it should be type caste into interger pointer

    // C:
    // int *p = (int *) malloc(5 * sizeof(int)); Allocate heap memory, which is located outside the program's scope 

    // C++:
    // unique ptr is better in most cases, since it's memory allocation will be flushed once the code execution gets out of scope
    {
        unique_ptr<int> p = make_unique<int>(123);
    }

    // int a = 10;
    // int *b;
    // b = &a;

    // cout << *b << endl;

    return 0;
}
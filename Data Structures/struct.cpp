/*
    struct is used to define user-defined datataypes
    struct can be defined as a combination of data types that create a datatype under the same name

    for example: rectangle has two sides, length & width 
    a rectangle is a combination of both length and width
    therefore, we can conclude rectangle as a struct

    * * * * * * *
    *           *
    * * * * * * *

    the size of a struct is the total size of it's members
    struct Rectangle
    {
        int length; -> 4 bytes
        int width;  => 4 bytes +
                      ===========
                       8 bytes
    };

    Main Memory
    =================
    Heap

    Stack 

    Main
        Varibles created in the main
        Rectangle   * * * * * * *
                    * 10  * 5   *
                    * * * * * * *
    
    Code Section
        ----------------------------------------------------------------
        ----------------------------------------------------------------


    * Struct usage
    1. Complex Number
        a + i b
        where i is imaginary number
        a and b are real number

        struct ComplexNumber {
            int real;
            int img;
        }
*/

#include <iostream>
using namespace std;

struct Rectangle {
    int length;
    int width;
};

int main() {
    // Rectangle r;           // declaration 
    Rectangle r = {10, 5}; // declaration + initialization

    // To access the member of a struct, use dot notation
    cout << r.length << " " << r.width << endl;
    
    // Declaration of array of struct
    Rectangle arrR[2] = {
        {10, 5},
        {2, 3},
    };

    // Accessing array of struct 
    cout << arrR[1].length << "  " << arrR[1].width << endl;
}
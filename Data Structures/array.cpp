#include <iostream>
using namespace std;

int main() 
{
    /* Array are to declare a set of variable under the same name */
    /* Therefore in this case, we're declaring 5 int under the name A */
    int A[5];
    int B[5] = {2, 4, 6, 8, 10};

    /*
        int i -> declared only ONCE, not redeclared on each iteration
        i++   -> i is incremented everytime an iteration finished executing
    */
    for(int i = 0 ; i < 5; i++)
    {
        cout << B[i] << " " ;
    }

    /* Array index start from 0, therefore, when we're declaring array with a size of 5, then the indexes will be {0, 1, 2, 3, 4}*/
    /* Each program's data is stored in the main memory. It's devided into 4 sections: heap, stack and code solution*/

    /*
    Main Memory
    =================
    Heap

    Stack 

    Main
        Varibles created in the main
        A -> 18 5 7 3 9
    
    Code Section
        ----------------------------------------------------------------
        ----------------------------------------------------------------
    */

    return 0;
}
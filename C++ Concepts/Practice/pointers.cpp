#include <iostream>
using namespace std;

int main()
{
    // Creating array in stack
    int A[5] = {2, 4, 6, 8, 10};
    int *p;
    p = A;

    for(int i = 0; i < 5; i++)
        cout << p[i] << endl;

    cout << "\n";

    // Creating array in heap
    // C
    p = (int *) malloc(5 * sizeof(int));
    p[0] = 10, p[1] = 15, p[2] = 20, p[3] = 25, p[4] = 25;
    for(int i = 0; i < 5; i++)
        cout << p[i] << endl;

    free(p);

    cout << "\n";

    // C++
    p = new int[5];
    p[0] = 30, p[1] = 35, p[2] = 40, p[3] = 45, p[4] = 50;
    for(int i = 0; i < 5; i++)
        cout << p[i] << endl;

    delete []p;
}
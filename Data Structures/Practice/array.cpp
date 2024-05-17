#include <iostream>
#include <stdio.h>

using namespace std;

void Array() {
    int A[10] = {2, 4, 7};

    int B;
    cin >> B ;

    cout << sizeof(A) << endl;
    cout << A[1]      << endl;
    printf("%d", A[2]);
}

void ForEachLoop() {
    int A[10] = {2, 4, 7};

    for(int x:A)
    {
        cout << x << " "<< endl;
    }

} 

int main() 
{
    ForEachLoop();
    return 0;
}
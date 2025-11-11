#include <bits/stdc++.h>
using namespace std;

int main() {
    int *q = (int *) malloc(5 * sizeof(int));

    q[0] = 10;
    cout << q[0] << endl;

    // int **q = (int **) malloc(5 * sizeof(int *));

    // int a = 1, b = 2, c = 3, d = 4, e = 5;
    // q[0] = &a;
    // q[1] = &b;
    // q[2] = &c;
    // q[3] = &d;
    // q[4] = &e;

    // for(int i = 0; i < 5; i++) {
    //     cout << **(q + i) << endl;
    // }

    return 0;
}
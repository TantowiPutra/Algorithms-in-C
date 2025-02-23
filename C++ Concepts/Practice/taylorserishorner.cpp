#include <iostream>
using namespace std;

double TaylorSeriesHorner(int n, int x) {
    if(x == 0 ) {
        return 1;
    } else {
        return TaylorSeriesHorner(n, x -1) * (1 + n / x); 
        // return 1 + (x / n) * TaylorSeriesHorner(n - 1, x);  // Correct recurrence relation 
    }
}

double TaylorSeriesHorner2(int n, int x) {
    static double r = 1;
    if(x == 0) {
        return r;
    } else {
        r = 1 + r * n / x; 

        return TaylorSeriesHorner2(n, x - 1);
    }
}

int main() {
    int n = 1, x = 10;

    cout << TaylorSeriesHorner(n, x) << endl;
    cout << TaylorSeriesHorner2(n, x) << endl;

    return 0;
}
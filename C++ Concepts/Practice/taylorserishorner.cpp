#include <iostream>
using namespace std;

float TaylorSeriesHorner(int n, int x) {
    if(x == 0 ) {
        return 1;
    } else {
        return TaylorSeriesHorner(n, x -1) * (1 + n / x);
    }

}

float TaylorSeriesHorner2(int n, int x) {
    static float r = 1;
    if(x == 0) {
        return r;
    } else {
        r = r * (1 + (n / x));

        return TaylorSeriesHorner2(n, x - 1);
    }
}

int main() {
    int n = 3, x = 1;

    cout << TaylorSeriesHorner(n, x) << endl;
    cout << TaylorSeriesHorner2(n, x) << endl;

    return 0;
}
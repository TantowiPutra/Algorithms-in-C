// Online C++ compiler to run C++ program online
#include <iostream>
#include <string>
using namespace std;


// TIME COMPLEXITY O(N)
float TaylorSeries(int n, int x) {
    static float p = 1, f = 1;
    
    if(x == 0) {
        return 1;
    } else {
        float r = TaylorSeries(n, x - 1);
        p = p * n;
        f = f * x;
        
        return r + (p / f);
    }
}

int main() {
    int n = 2;
    int x = 4;
    
    cout << TaylorSeries(n, x) << endl;

    return 0;
}
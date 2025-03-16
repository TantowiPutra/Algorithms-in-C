// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

int Fact(int n) {
    if(n == 1)
        return 1;
    
    return n * Fact(n - 1);
}

void initializeMemo(int n, int memoArr[]) {
    for(int i = 0; i < n; i++) {
        memoArr[i] = -1;
    }
}

int nCrFormula(int n, int r) {
    int t1,t2, t3;
    t1 = Fact(n);
    t2 = Fact(r);
    t3 = Fact(n - r);

    return t1 / (t2 * t3);
}

int nCrPascal(int n, int r) {
    if(r == 0 || r == n) 
        return 1;
    else 
        return nCrPascal(n - 1, r -1) + nCrPascal(n - 1, r);
}

int main() {
    // COMBINATION nCr
    int n = 5;
    int r = 3;
    
    int memoArr[n];
    initializeMemo(n, memoArr);
    nCrFormula(n, r);
    cout << "nCr Using Formula: " << nCrFormula(n, r) << endl; 
    cout << "nCr Using Pascal: "    << nCrPascal(n, r) << endl; 
} 
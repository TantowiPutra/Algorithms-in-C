// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

int fib(int n) {
    if(n <= 1) 
        return n;
    return fib(n - 2) + fib(n - 1); 
}

int fibIterative(int n) {
    int t0 = 0, t1 = 1, s;
    
    if(n <= 1) 
        return n;
    
    for(int i = 2; i <= n; i++) {
        s = t0 + t1;
        t0 = t1;
        t1 = s;
    }
    
    return s;
}

int F[9999];
int fibMemo(int n) {
    if(n <= 1) {
        F[n] = n;
        return n;
    } else {
        if(F[n - 2] == -1) {
            F[n - 2] = fibMemo(n - 2);
        }
        
        if(F[n - 1] == -1) {
            F[n - 1] = fibMemo(n - 1);
        }
        
        F[n] = F[n - 2] + F[n -1];
        return F[n];
    }
}

void setGlobalVar(int n) {
    for(int i = 0; i < n; i++) {
        F[i] = -1;
    }
}

int main() {
    int n = 10;
    setGlobalVar(n);
    
    cout << fib(n) << endl;
    cout << fibIterative(n) << endl;
    cout << fibMemo(n) << endl;

    return 0;
}
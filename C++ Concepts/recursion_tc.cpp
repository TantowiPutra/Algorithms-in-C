#include <iostream>
using namespace std;

// Time Complaxity Analysis of Recursive Functions
void func1(int n) {           // T(n)
    if(n > 0) {               // 1
        cout << n << endl;    // 1
        func1(n - 1);         // T(n -1)       +
                              // ================
                              // T(n) = T(n - 1) + 2


        // Recursion
        /*
            T(n) = if n = 0, then The time complexity will be O(1)
            ELSE it will be T(n) = T(n - 1) + 2;
        */
    }
}

int main() {
    int x = 3;
    func1(x);

    return 0;  
}
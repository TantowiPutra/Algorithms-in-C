#include <iostream>
using namespace std;

int pow(int m, int n)
{
    if(n == 0)
        return 1;
    else
        return pow(m, n - 1) * m;
}

int powOptimized(int m, int n)
{
    if(n == 0)
        return 1;

    if(n % 2 == 0) {
        return powOptimized(m * m, n / 2);
    } else {
        return m * powOptimized(m * m, n / 2);
    }

    //  2 ^ 4
    /*
        powOptimized(2 * 2, 2) (return 16)
        powOptimized(4 * 4, 1) (return 16) 
        16 * (powOptimized(16 * 16, 1)) ~ 1 = 16 * 1 = (return 16)  
        
    */
}

int main() {
    cout << pow(2, 5) << endl;
}
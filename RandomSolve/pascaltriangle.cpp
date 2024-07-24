// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

void printPascalTriangle(int n) {
    for(int line = 1; line <= n; line++) {
        // OUTPUT WHITESPACE
        for(int x = 0; x < n - line; x++) cout << "  ";
        
        int c = 1;
        for(int y = 1; y <= line; y++) {
            printf("%4d", c);
            c = c * (line - y) / y;
        }
        
        cout << endl;
    }
}

int main() {
    int number = 10;
    printPascalTriangle(number);

    return 0;
}
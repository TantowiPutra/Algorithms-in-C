#include <iostream>
using namespace std;

int main() {
    int N = 6;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < 3 * (N - i) - 3; j++) {
            cout << " ";
        }

        for(int k = 0; k < i * 2 + 1; k++) {
            cout << "*  ";
        }

        cout << "\n";
    }
}
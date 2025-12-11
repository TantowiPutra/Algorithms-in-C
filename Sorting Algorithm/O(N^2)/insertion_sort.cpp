// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

void printVector(vector<int> & v) {
    for(auto a : v) {
        cout << a << " ";
    }
    
    cout << endl;
}

int main() {
    vector<int> v = {100, 3 , 8, 8, 4, 1, 5, 6};
    
    for(int i = 1; i < v.size(); i++) {
        int numInsert = v[i];
        int j = i - 1;

        while(j >= 0 && numInsert < v[j]) {
            v[j + 1] = v[j];
            j--;
        }

        v[j + 1] = numInsert;
    }
    
    printVector(v);

    return 0;
}
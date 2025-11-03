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
        int n = 0;
        int numToInsert = v[i];
        
        while(v[n] < v[i] && n < i) n++;
        
        for(int j = i; j > n; j--) {
            v[j] = v[j - 1];   
        }
        
        v[n] = numToInsert;
    }
    
    printVector(v);

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v = {8, 6, 3, 2, 5, 4};
    int n = v.size();
    
    for(int i = 0; i < n; i++) {
        int k = i; // Assume Current Element is the Smallest
        
        for(int j = i + 1; j < n; j++) {
            if(v[j] < v[k]) {
                k = j;
            }
        }
        
        swap(v[k], v[i]);
    }
    
    for (int a : v) cout << a << " ";
    cout << endl;
    
    return 0;
}
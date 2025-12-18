#include <bits/stdc++.h>
using namespace std;

void printArr(vector<int> &v) {
    for(int a : v) cout << a << " ";
    cout << endl;
}

void quickSort(vector<int> &v, int left, int right) {
    if(left >= right) return;
    
    int i = left, j = right;
    int pivotValue = v[left];
    
    while(i <= j) {
        while(v[i] < pivotValue) i++;
        while(v[j] > pivotValue) j--;
        
        if(i <= j) {
            swap(v[i], v[j]);
            i++;
            j--;
        } 
    }
    
    quickSort(v, left, j);
    quickSort(v, i, right);
}

int main() {
    vector<int> v = {50, 70, 60, 90, 40, 80, 10, 20, 30};
    int n = v.size();
    
    quickSort(v, 0, n - 1);
}
// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int l, int mid, int r) {
    int n1 = mid - l + 1;
    int n2 = r - mid;
    
    vector<int> v1, v2;
    for(int i = 0; i < n1; i++) {
        v1.push_back(arr[l + i]);
    }
    
    for(int i = 0; i < n2; i++) {
        v2.push_back(arr[mid + 1 + i]);
    }
    
    // Insert Value ke Original Array
    int i = 0, j = 0, k = l;
    
    while(i < n1 && j < n2) {
        if(v1[i] <= v2[j]) {
            arr[k++] = v1[i++];
        } else {
            arr[k++] = v2[j++];
        }
    }
    
    while(i < n1) {
        arr[k++] = v1[i++];
    }
    
    while(j < n2) {
        arr[k++] = v2[j++];
    }
}

void mergeSort(vector<int> &arr, int l, int r) {
    if(l >= r) return;
    
    int mid = l + (r - l) / 2;
    
    mergeSort(arr, l, mid);
    mergeSort(arr, mid + 1, r);
    
    merge(arr, l, mid, r);
}

void printArr(vector<int> &arr) {
    for(int &x : arr) cout << x << " ";
    cout << endl;
}

int main() {
    vector<int> arr = {30, 20 , 10, 5, -10, 20, 5, 35};
    mergeSort(arr, 0, arr.size() - 1);
    printArr(arr);
    
    return 0;
}
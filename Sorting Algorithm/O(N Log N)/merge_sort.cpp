#include <bits/stdc++.h>
using namespace std;

vector<int> temp;
void merge(vector<int> &arr, int l, int mid, int r) {    
    int i = l, j = mid + 1, k = l;

    while(i <= mid && j <= r) {
        if(arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }
    
    while(i <= mid) {
        temp[k++] = arr[i++];
    }
    
    while(j <= r) {
        temp[k++] = arr[j++];
    }

    for(int i = l; i < k; i++) arr[i] = temp[i];
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
    temp.resize(arr.size());
    mergeSort(arr, 0, arr.size() - 1);
    printArr(arr);
    
    return 0;
}
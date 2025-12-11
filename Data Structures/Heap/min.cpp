#include <bits/stdc++.h>
using namespace std;

void print(vector<int> &minHeap) {
    for (int &a : minHeap) cout << a << " ";
    cout << endl;
}

// O(Log N) Heap Insertion Process
void insert(vector<int> &minHeap, int val) {
    minHeap.push_back(val);
    
    int currIdx   = minHeap.size() - 1;
    int parentIdx = (currIdx - 1) / 2;

    while(currIdx > 0 && val < minHeap[parentIdx]) {
        minHeap[currIdx] = minHeap[parentIdx];
        currIdx          = parentIdx;
        parentIdx        = (currIdx - 1) / 2; 
    }

    minHeap[currIdx] = val;
}

// O(N Log N) Heap Insertion Process
void insertInPlace(vector<int> &minHeap, int idx) {
    int temp = minHeap[idx];

    while(idx > 0 && temp < minHeap[(idx - 1) / 2]) {
        minHeap[idx] = minHeap[(idx - 1) / 2];
        idx = (idx - 1) / 2;
    }

    minHeap[idx] = temp;
}

void removeHeap(vector<int> &minHeap) {
    int n = minHeap.size();
    if(n == 0) return;
    int temp = minHeap[n - 1];
    minHeap[0] = temp;
    minHeap.pop_back();

    int idx   = 0;
    int left  = (idx * 2) + 1;
    int right = (idx * 2) + 2;

    while(left < minHeap.size()) {
        int smallest = idx;

        if(minHeap[left] < minHeap[smallest]) 
            smallest = left; 

        if(right < minHeap.size() && minHeap[right] < minHeap[smallest]) 
            smallest = right;

        if(smallest == idx) break;
        swap(minHeap[smallest], minHeap[idx]);
        idx  = smallest;

        left  = (idx * 2) + 1;
        right = (idx * 2) + 2; 
    }
}

void heapify(vector<int> &arr, int idx, int n) {
    int smallest = idx;
    int left     = (idx * 2) + 1;
    int right    = (idx * 2) + 2;

    if(left < n && arr[left] < arr[smallest]) 
        smallest = left;

    if(right < n && arr[right] < arr[smallest])
        smallest = right;

    if(idx == smallest) return;
    swap(arr[idx], arr[smallest]);
    heapify(arr, smallest, n);
}

void buildHeap(vector<int> &arr) {
    int n = arr.size();
    for(int i = (n / 2) - 1; i >= 0; i--) {
        heapify(arr, i, n);
    }
}

int main() {
    vector<int> minHeap;
    insert(minHeap, 10);
    insert(minHeap, 5);
    print(minHeap);

    vector<int> arr = {1, 6, 3, 2 , 9, 4, 7};
    for(int i = 1; i < arr.size(); i++) {
        insertInPlace(arr, i);
    }
    print(arr);
    removeHeap(arr);
    print(arr);

    vector<int> arr2 = {1, 6, 3, 2, 9, 4, 7};
    buildHeap(arr2);
    print(arr2);

    return 0;
}
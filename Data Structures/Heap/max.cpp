#include <bits/stdc++.h>
using namespace std;

void print(vector<int> &maxHeap) {
    for(int &a : maxHeap) cout << a << " ";
    cout << endl;
}

// O(Log N) Heap Insertion Process
void insert(vector<int> &maxHeap, int val) {
    maxHeap.push_back(val);
    
    int currIdx   = maxHeap.size() - 1;
    int parentIdx = (currIdx - 1) / 2; 

    while(currIdx > 0 && val > maxHeap[parentIdx]) {
        maxHeap[currIdx] = maxHeap[parentIdx];
        
        currIdx = parentIdx;
        parentIdx = (currIdx - 1) / 2;
    }
    
    maxHeap[currIdx] = val;
}

// O(N Log N) Heap Insertion Process
void insertInPlace(vector<int> &maxHeap, int idx) {
    int temp = maxHeap[idx];

    while(idx > 0 && temp > maxHeap[(idx - 1) / 2]) {
        maxHeap[idx] = maxHeap[(idx - 1) / 2];
        idx          = (idx - 1) / 2;
    }

    maxHeap[idx] = temp;
}

void removeHeap(vector<int> &maxHeap) {
    int n       = maxHeap.size();
    if(n == 0) return;

    int temp    = maxHeap[n - 1];
    maxHeap[0]  = temp;
    maxHeap.pop_back();

    int idx     = 0;
    int left    = (idx * 2) + 1;
    int right   = (idx * 2) + 2;

    while(left < maxHeap.size()) {
        int largest = idx;

        if(maxHeap[left] > maxHeap[largest]) 
            largest = left;

        if(right < maxHeap.size() && maxHeap[right] > maxHeap[largest])
            largest = right;

        if(idx == largest) break;
        swap(maxHeap[idx], maxHeap[largest]);
        idx = largest;

        left  = (idx * 2) + 1;
        right = (idx * 2) + 2; 
    }
}

int main() {
    vector<int> maxHeap;
    insert(maxHeap, 1);
    insert(maxHeap, 2);
    insert(maxHeap, 3);
    insert(maxHeap, 4);
    print(maxHeap);

    vector<int> arr = {1, 6, 3, 2 , 9, 4, 7};
    for(int i = 1; i < arr.size(); i++) {
        insertInPlace(arr, i);
    }
    print(arr);
    removeHeap(arr);
    print(arr);

    return 0;
}
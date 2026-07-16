// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

vector<int> arr, segmentTree;
void build(int node, int l, int r) {
    if(l == r) {
        segmentTree[node] = arr[l];
        return;
    }
    
    int mid = l +(r - l) / 2;
    
    build(node * 2, l, mid);
    build(node * 2 + 1, mid + 1, r);
    
    segmentTree[node] = segmentTree[node * 2] + segmentTree[node * 2 + 1];
}

int query(int node, int tl, int tr, int l, int r)
{
    if (r < tl or tr < l)
        return 0;

    if (l <= tl and tr <= r)
        return segmentTree[node];
        
    int tm = tl + (tr - tl) / 2;

    return query(2 * node, tl, tm, l, r)
           + query(2 * node + 1, tm + 1, tr, l, r);
}

void update(int node, int l, int r, int idx, int val) {
    if(l == r) {
        arr[idx] += val;
        segmentTree[node] += val;
        return;
    }
    
    int mid = l + (r - l) / 2;
    
    if(l <= idx && idx <= mid)
        update(node * 2, l, mid, idx, val);
    else
        update(node * 2 + 1, mid + 1, r, idx, val);
        
    segmentTree[node] = segmentTree[node * 2] + segmentTree[node * 2 + 1];
}

int main() {
    int n = 6;
    arr = { 0, 1, 3, 5, -2, 3 };
    
    // Segment Tree Size
    segmentTree.resize(4 * n);
    
    // Build Segment Tree
    build(1, 0, n - 1);
    cout << "Sum of values in range 0-4 are: "
         << query(1, 0, n - 1, 0, 4) << "\n";
    
    // Update Segment Tree
    update(1, 0, n - 1, 1, 100);
    cout << "Value at index 1 increased by 100\n";
    cout << "sum of value in range 1-3 are: "
         << query(1, 0, n - 1, 1, 3) << "\n";

    return 0;
}
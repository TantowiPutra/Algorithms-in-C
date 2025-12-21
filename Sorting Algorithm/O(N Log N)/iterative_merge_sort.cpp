#include <bits/stdc++.h>
using namespace std;

vector<int> temp;

void merge(vector<int> &v, int left, int mid, int right) {
    int i = left, j = mid + 1, k = left;

    while(i <= mid && j <= right) {
        if(v[i] <= v[j]) {
            temp[k++] = v[i++];
        } else {
            temp[k++] = v[j++];
        }
    }

    while(i <= mid) {
        temp[k++] = v[i++];
    }

    while(j <= right) {
        temp[k++] = v[j++];
    }

    while(left <= right) {
        v[left] = temp[left];
        left++;
    }
}

int main() {
    vector<int> v = {8, 3, 7, 4, 9, 2, 6, 5};
    int n = v.size();
    temp.resize(n);

    for(int size = 1; size < n; size *= 2) {
        for(int start = 0; start + size < n; start += size * 2) {
            int left  = start;
            int mid   = start + size - 1;
            int right = min(start + (size * 2 - 1), n - 1);
            
            merge(v, left, mid, right);
        }
    }

    for(int a : v) cout << a << " ";
    cout << endl;

    return 0;
}
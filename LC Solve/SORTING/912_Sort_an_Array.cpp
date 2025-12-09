#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void merge(vector<int>& a, vector<int>& temp, int left, int mid, int right) {
        int i = left, j = mid + 1, k = left;

        while (i <= mid && j <= right)
            temp[k++] = (a[i] <= a[j]) ? a[i++] : a[j++];

        while (i <= mid) temp[k++] = a[i++];
        while (j <= right) temp[k++] = a[j++];

        for (int x = left; x <= right; x++)
            a[x] = temp[x];
    }

    vector<int> sortArray(vector<int>& nums) {
        int n  = nums.size();
        vector<int> temp(n);

        for(int i = 1; i < n; i *= 2) { // UKURAN WINDOW
            for(int j = 0; j < n - i; j += i * 2) { // CHUNK WINDOW
                int mid   = j + i - 1;
                int right = min(j + ((i * 2) - 1), n - 1);
                merge(nums, temp, j, mid, right);
            }
        }

        return nums;
    }
};
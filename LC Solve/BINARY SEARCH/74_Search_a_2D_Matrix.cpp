#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r = matrix.size(), c = matrix[0].size();
        int left = 0, right = r * c - 1;

        while(left <= right) {
            int mid    = left + (mid - left) / 2;
            int midVal = matrix[mid / c][mid % c];

            if(midVal < target) {
                left = mid + 1;
            } else if(midVal > target) {
                right = mid - 1;
            } else {
                return true;
            }
        }
        
        return false;
    }
};
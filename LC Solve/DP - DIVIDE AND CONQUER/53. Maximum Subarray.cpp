#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // O(N^2) -> TLE
    int bruteForce(vector<int> &nums) {
        int n = nums.size();
        int maxSum = nums[0];

        for(int i = 0; i < n; i++) {
            int sum = 0;

            for(int j = i; j < n; j++) {
                sum += nums[j];
                maxSum = max(maxSum, sum);
            }
        }

        return maxSum;
    }

    int kadaneAlgorithm(vector<int> &nums) {
        int n      = nums.size();
        int maxSum = nums[0];

        int maxEnd = nums[0];

        for(int i = 1; i < n; i++) {
            maxEnd = max(maxEnd + nums[i], nums[i]);
            maxSum = max(maxSum, maxEnd);
        } 

        return maxSum;
    }

    // O(N Log (N)) 
    int divideAndConquer(vector<int> &nums, int l, int r) {
        /*
            3 Kemungkinan Max Sum Range
            1. Semua Ada Disebelah kiri mid  [L, MID - 1]
            2. Semua Ada Disebelah kanan mid [MID + 1, R]
            3. Terdiri dari mid + Sebagian sebelah kiri dari mid + Sebagian sebelah kanan dari mid 
               [L', R'] = [L', mid - 1] + mid + [mid + 1, R']
               dimana L' >= L dan R <= R' 
        */

        if(l > r) return INT_MIN;
        int mid = l + (r - l) / 2;
        int leftSum = 0, rightSum = 0;

        for(int i = mid - 1, currSum = 0; i >= l; i--) {
            currSum += nums[i];
            leftSum  = max(leftSum, currSum);
        }

        for(int i = mid + 1, currSum = 0; i <= r; i++) {
            currSum += nums[i];
            rightSum = max(rightSum, currSum);
        }

        return max({
            divideAndConquer(nums, l, mid - 1),
            divideAndConquer(nums, mid + 1, r),
            leftSum + nums[mid] + rightSum
        });
    }

    int maxSubArray(vector<int>& nums) {
        return divideAndConquer(nums, 0, nums.size() - 1);
        return kadaneAlgorithm(nums);
        return bruteForce(nums);
    }
};
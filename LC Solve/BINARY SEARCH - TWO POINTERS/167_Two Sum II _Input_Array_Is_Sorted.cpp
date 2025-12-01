#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // O(N)
    vector<int> twoPointer(vector<int> &numbers, int target) {
        int l = 0, r = numbers.size() - 1;

        while(l < r) {
            if(numbers[l] + numbers[r] > target) {
                r--;
            } else if(numbers[l] + numbers[r] < target) {
                l++;
            } else {
                return {l + 1, r + 1};
            }
        }

        return {-1, -1};
    }

    // O(N Log N)
    vector<int> binarySearch(vector<int> &numbers, int target) {
        int n = numbers.size();

        for(int i = 0; i < n; i++) {
            int c = target - numbers[i];
            int l = i + 1, r = n - 1;

            while(l <= r) {
                int mid = l + (r - l) / 2;

                if(numbers[mid] < c) {
                    l = mid + 1;
                } else if(numbers[mid] > c) {
                    r = mid - 1;
                } else {
                    return {i + 1, mid + 1};
                }
            }
        }

        return {-1, -1};
    }

    vector<int> twoSum(vector<int>& numbers, int target) {
        return binarySearch(numbers, target);
        return twoPointer(numbers, target);
    }
};
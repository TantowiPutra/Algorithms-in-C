#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // BUAT JADI HEAP O (N Log N)
        int n = nums.size();

        for(int i = 1; i < n; i++) {

            int currIdx = i;
            int parent  = (currIdx - 1) / 2;
            
            while(i > 0 && nums[currIdx] > nums[parent]) {
                swap(nums[currIdx], nums[parent]);
                currIdx = parent;
                parent  = (currIdx - 1) / 2;
            }
        }

        // EXTRACT HEAP O(K LOG K)
        k--;
        while(k > 0) {
            int temp = nums.back();
            nums.pop_back();
            nums[0] = temp;

            int idx   = 0;
            int left  = (idx * 2) + 1;
            int right = (idx * 2) + 2; 
            int sz  = nums.size();

            while(left < sz) {
                int largest = idx;

                if(nums[left] > nums[largest]) largest = left;
                if(right < n && nums[right] > nums[largest]) largest = right;
                if(largest == idx) break;
                swap(nums[largest], nums[idx]);

                idx = largest;
                left  = (idx * 2) + 1;
                right = (idx * 2) + 2; 
            }

            k--;
        }

        return nums[0]; // TOTAL O(N Log N + K Log K)
    }
};

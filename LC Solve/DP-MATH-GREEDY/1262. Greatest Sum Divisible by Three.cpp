#include <bits/stdc++.h>
using namespace std;

/*
    TODO1: IMPLEMENT DP APPROACH (1D / 2D)
    TODO2: IMPLEMENT SORTING TECHNIQUE

    The idea is to find the highest possible sum, such that sum % 3 == 0
    The sum doesn't have to be a subarray: it's allowed to be a subset of the array

    Mathematic Approach:
    1. Maintain running sum, check if sum % 3 == 0, if 0, return sum.
    2. If it's not 0, then the remaining will be either 1 or 2.
    3. If 1, we can subsract the sum with the following option:
       - nums[i] such that nums[i] % 3 == 1 OR
       - (nums[i] + nums[j]) % 3 == 1, for example nums[i] = 5, nums[j] = 5, notice how nums[i] and nums[j] mod 3's result both are 2
    4. If 4, we can subsract the sum with the following option:
       - nums[i] such that nums[i] % 3 == 2 OR
       - (nums[i] + nums[j]) % 3 == 2, for example nums[i] = 1, nums[j] = 1, notice how nums[i] and nums[j] mod 3's result both are 1
    5. While maintaining the running sum, we keep track of top 2 minimum number of which are having remaining 1 and 2 when mod with 3
    6. Substract the running sum with the options on step 3/4, depending on the remaining of running sum mod 3
*/

class Solution {
public:
    static int maxSumDivThree(vector<int>& nums) {
        int sum = 0;

        int r11 = INT_MAX, r12 = INT_MAX;
        int r21 = INT_MAX, r22 = INT_MAX;

        for(int &x : nums) {
            sum += x;

            if(x % 3 == 1) {
                if(x < r11) {
                    r12 = r11;
                    r11 = x;
                } else if(x < r12) {
                    r12 = x;
                }
            } else if(x % 3 == 2) {
                if(x < r21) {
                    r22 = r21;
                    r21 = x;
                } else if(x < r22) {
                    r22 = x;
                }
            }
        }

        if(sum % 3 == 0) return sum;

        if(sum % 3 == 1) {
            int firstOption  = r11 != INT_MAX ? r11 : INT_MAX;
            int secondOption = r21 != INT_MAX && r22 != INT_MAX ? r21 + r22 : INT_MAX;

            sum -= min(firstOption, secondOption);
        } else if(sum % 3 == 2) {
            int firstOption  = r21 != INT_MAX ? r21 : INT_MAX;
            int secondOption =  r11 != INT_MAX && r12 != INT_MAX ? r11 + r12 : INT_MAX;

            sum -= min(firstOption, secondOption);
        }

        return sum;
    }
};

int main() {
    vector<int> nums = {3, 6, 5, 1, 8};
    int res = Solution::maxSumDivThree(nums);

    cout << res << endl;
}
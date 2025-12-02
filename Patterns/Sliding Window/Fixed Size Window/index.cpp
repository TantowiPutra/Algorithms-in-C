#include <bits/stdc++.h>
using namespace std;

void print(vector<int> &v) {
    for(int x : v) {
        cout << x << " ";
    }

    cout << endl;
}

vector<int> windowSumSizeK() {
    vector<int> nums = {1, 3, 2, 6, -1, 4, 1, 8, 2};
    int k = 3;
    int n = nums.size();

    vector<int> res;

    int windowSum = 0;
    for(int i = 0; i < k; i++) {
        windowSum += nums[i];
    }

    res.push_back(windowSum);

    for(int i = k; i < n; i++) {
        windowSum += nums[i] - nums[i - k];
        res.push_back(windowSum);
    }

    print(res);
}

int main() {
    windowSumSizeK();
}
#include <bits/stdc++.h>
using namespace std;

void print(vector<int> &v) {
    for(int x : v) {
        cout << x << " ";
    }

    cout << endl;
}

int main() {
    int k = 3;
    vector<int> nums = {1, 3, 2, 6, -1, 4, 1, 8, 2};

    deque<int> minDq;
    deque<int> maxDq;

    int n = nums.size();
    vector<int> maxInWindow;
    vector<int> minInWindow;

    for(int i = 0; i < n; i++) {
        if(!maxDq.empty() && maxDq.front() <= i - k) maxDq.pop_front();
        if(!minDq.empty() && minDq.front() <= i - k) minDq.pop_front();

        while(!maxDq.empty() && nums[maxDq.back()] < nums[i]) maxDq.pop_back();
        while(!minDq.empty() && nums[minDq.back()] > nums[i]) minDq.pop_back();

        maxDq.push_back(i);
        minDq.push_back(i);
        
        if(i >= k - 1) minInWindow.push_back(nums[minDq.front()]);
        if(i >= k - 1) maxInWindow.push_back(nums[maxDq.front()]);
    }

    print(maxInWindow);
    print(minInWindow);
}
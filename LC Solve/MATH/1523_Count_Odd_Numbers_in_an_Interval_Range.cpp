#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int bruteForce(int low, int high) {
        int cnt = 0;
        for(int i = low; i <= high; i++) if(i % 2 == 1) cnt++;

        return cnt;
    }

    int optimized(int low, int high) {
        /*
            Dry Run:
            1 2 3 4 5 6 7 8 9 10 -> Low = 4, High = 10
                    ^   ^   ^

            Di range 4 sampe 10, jumlah odd dan even seimbang, jadinya:
            countOdd = (high - low) / 2

            Dry Run:
            1 2 3 4 5 6 7 8 9 10 -> Low = 5, High = 10
                    ^   ^   ^

            Range 5 Sampe 10 -> Low = 5, High 10
            Di range 5 sampe 10, setidaknya ada salah satu odd, jadinya:
            countOdd = (high - low) / 2 + 1
        */

        if(low % 2 == 0 && high % 2 == 0) return (high - low) / 2;
        else return (high - low) / 2 + 1;
    }

    int countOdds(int low, int high) {
        return optimized(low, high);
        return bruteForce(low, high);
    }
};
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        // 1, 2, -3, 3, 1

        ListNode dummy(0, head);
        ListNode *start = &dummy;
        
        unordered_map<int, ListNode *> map;
        map[0] = start;

        start = start->next;
        int prefixSum = 0;

        while(start) {
            prefixSum += start->val;
            
            if(map.find(prefixSum) != map.end()) {
                /*
                0 1, 2, -3, 3, 1
                         ^
                0    PrefixSum = 0 Here

                Kalo kembali ke nilai yang sama (Prefix sum yang sama sudah terecord), artinya antara node saat ini dan previous node sumnya == 0
                */

                

                ListNode *prev = map[prefixSum];
                start          = prev->next;

                int temp = prefixSum + start->val;
                while(temp != prefixSum) {
                    map.erase(temp);
                    start = start->next;
                    temp += start->val;
                }

                prev->next = start->next; 
            } else {
                map[prefixSum] = start;
            }
            
            start = start->next;
        }


        return dummy.next;
    }
};
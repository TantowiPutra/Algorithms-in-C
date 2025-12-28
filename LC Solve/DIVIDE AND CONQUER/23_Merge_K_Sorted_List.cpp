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
    ListNode *splitList(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head->next;

        while(fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode *temp = slow->next;
        slow->next = nullptr;

        return temp;
    }

    ListNode *merge(ListNode *l1, ListNode *l2) {
        if(!l1) return l2;
        if(!l2) return l1;

        ListNode dummy(0);
        ListNode *tail = &dummy;

        while(l1 && l2) {
            if(l1->val <= l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }

            tail = tail->next;
        }

        tail->next = l1 ? l1 : l2;

        return dummy.next;
    } 

    ListNode *divide(ListNode *head) {
        if(!head || !head->next) return head;

        ListNode *mid = splitList(head);

        ListNode *leftList  = divide(head);
        ListNode *rightList = divide(mid);

        return merge(leftList, rightList);
    }

    ListNode *priorityQueue(vector<ListNode *> lst) {
        auto cmp = [](ListNode *a, ListNode *b) {
            return a->val > b->val;
        };

        priority_queue<
            ListNode*,
            vector<ListNode *>,
            decltype(cmp)
        > pq(cmp);

        for (ListNode *l : lst) {
            if(l) pq.push(l);
        }

        ListNode dummy(0);
        ListNode *tail = &dummy;

        while(!pq.empty()) {
            ListNode *root = pq.top(); pq.pop();

            tail->next = root;
            tail       = tail->next;

            if(root->next)
                pq.push(root->next);
        }

        return dummy.next;
    }

    ListNode* sortList(ListNode* head) {
        return divide(head);
    }   
};
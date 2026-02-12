#include <bits/stdc++.h>
using namespace std;

struct LinkedList {
    int val;
    LinkedList *next;
    
    LinkedList(int val) {
        this->val = val;
        this->next = nullptr;
    }
};

class HashMap {
    private:
        vector<LinkedList *> chain;
        
        int hashing(int val) {
            return val % 10;
        }
        
    public:
        HashMap() {
            for(int i = 0; i < 10; i++) {
                chain.push_back(new LinkedList(INT_MAX));
            }
        }
        
        void insert(int val) {
            int idx = this->hashing(val);
            LinkedList *head = this->chain[idx];
            
            while(head->next && head->next->val < val) {
                head = head->next;
            }
            
            LinkedList *newNode = new LinkedList(val);
            if(head->next) {
                newNode->next = head->next;
                head->next = newNode;
            } else {
                head->next = newNode;
            }
        }
        
        void printAll() {
            for(int i = 0; i < 10; i++) {
                LinkedList *head = this->chain[i]->next;
                while(head) {
                    cout << head->val << " ";
                    head = head->next;
                }
                
                cout << endl;
            }
        }
        
        int find(int val) {
            int idx = this->hashing(val);
            
            LinkedList *head = this->chain[idx]->next;
            while(head) {
                if(head->val == val) return val;
                head = head->next;
            }
            
            return -1;
        }
};

int main() {
    vector<int> nums = {16, 12, 25, 39, 6, 122, 5, 68, 75};
    HashMap map;
    
    for(const auto &num : nums) {
        map.insert(num);
    }
    map.printAll();
    cout << "Find Element (75) : "<< map.find(75) << endl;

    return 0;
}
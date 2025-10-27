#include <iostream>
using namespace std;

struct Node {
    int val;
    Node *next;

    Node(int v, Node *n = nullptr) {
        this->val  = v;
        this->next = n;
    }
};

void displayIterative(Node *head) {
    while(head) {
        cout << head->val << " ";
        head = head->next;
    }

    cout << endl;
}

void displayRecursive(Node *head) {
    if(!head) return;

    displayRecursive(head->next);
    cout << head->val << " ";
}

int countNode(Node *head) {
    if(!head) return 0;

    return 1 + countNode(head->next);
}

int sumAllNodes(Node *head) {
    if(!head) return 0;
    
    return head->val + sumAllNodes(head->next);
}

int findMax(Node *head) {
    if(!head) return 0;

    int maxVal = max(head->val, findMax(head->next));
    return maxVal;
}

int linearSearch(Node *head, int f) {
    if(!head)          return -1;
    if(head->val == f) return head->val;

    return linearSearch(head->next, f);
}

Node* insert(Node *head, Node *prev, int currIdx, int insertPos, int val) {
    if(insertPos == 1) {
        Node *newNode = new Node(val, head);
        return newNode;
    }

    if (!head) {
        if (currIdx == insertPos) {
            Node *newNode = new Node(val, nullptr);
            if (prev) prev->next = newNode;
            return newNode;
        }
        
        return nullptr;
    }

    if(currIdx == insertPos) {
        Node *newNode = new Node(val, head);
        prev->next = newNode;
        return newNode;
    }

    insert(head->next, head, currIdx + 1, insertPos, val);
    return head;
}

int main() {
    Node *fifth  = new Node(50, nullptr);
    Node *fourth = new Node(40, fifth);
    Node *third  = new Node(30, fourth);
    Node *second = new Node(20, third);

    Node *head = new Node(10, second);

    displayIterative(head);
    displayRecursive(head);
    cout << endl;

    cout << countNode(head) << endl;
    cout << sumAllNodes(head) << endl;
    cout << findMax(head) << endl;
    cout << linearSearch(head, 60) << endl;

    head = insert(head, nullptr, 1, 0, 70);
    displayIterative(head);

    return 0;
}
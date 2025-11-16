#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val, TreeNode *left = nullptr, TreeNode *right = nullptr) : val(val), left(left), right(right) {}
};

void preOrder(TreeNode *root) {
    if(!root) return;

    cout << root->val << " ";
    preOrder(root->left);
    preOrder(root->right);
}

int getHeight(TreeNode *root) {
    if(!root) return 0;

    int leftHeight  = getHeight(root->left);
    int rightHeight = getHeight(root->right);

    return 1 + max(leftHeight, rightHeight);
}

TreeNode *createFromPreOrder(vector<int> &v, int &idx, int minVal, int maxVal) {
    if(idx >= v.size()) return nullptr;

    int val = v[idx];
    if(val < minVal || val > maxVal) return nullptr;

    ++idx;
    TreeNode *root = new TreeNode(val);
    root->left  = createFromPreOrder(v, idx, minVal, val);
    root->right = createFromPreOrder(v, idx, val, maxVal);

    return root;
}

TreeNode* createFromPostOrder(vector<int> &v, int &idx, int minVal, int maxVal) {
    if (idx < 0) return nullptr;

    int val = v[idx];
    if (val < minVal || val > maxVal) return nullptr;

    idx--;
    TreeNode* root = new TreeNode(val);

    root->right = createFromPostOrder(v, idx, val, maxVal);
    root->left  = createFromPostOrder(v, idx, minVal, val);

    return root;
}

TreeNode *iterativeCreateFromPreOrder(vector<int> &v) {
    if(v.size() == 0) return nullptr;
    stack<TreeNode *> s;

    TreeNode *root = new TreeNode(v[0]);
    s.push(root);

    for(int i = 1; i < v.size(); i++) {
        TreeNode *curr       = new TreeNode(v[i]);
        TreeNode* lastPopped = nullptr;

        while(!s.empty() && s.top()->val < v[i]) {
            lastPopped = s.top();
            s.pop();
        }

        if(!lastPopped) {
            s.top()->left = curr;
        } else {
            lastPopped->right = curr;
        }

        s.push(curr);
    }

    return root;
}

TreeNode *findValue(TreeNode *root, int find) {
    while(root) {
        if(root->val == find) {
            return root;
        } else if(root->val > find) {
            root = root->left;
        } else if(root->val < find) {
            root = root->right;
        }
    }

    return nullptr; // Tidak Ketemu
}

TreeNode *inPre(TreeNode *root) {
    if(!root) return nullptr;

    root = root->left;
    while(root->right)
        root = root->right;

    return root;
}

TreeNode *inSucc(TreeNode *root) {
    if(!root) return nullptr;

    root = root->right;
    while(root->left)
        root = root->left;

    return root;
}

TreeNode* insertIterative(TreeNode *root, int val) {
    TreeNode *prev = nullptr;
    TreeNode *cpy  = root;

    while(cpy) {
        prev = cpy;

        if(cpy->val == val)
            return root;
        else if(cpy->val > val) 
            cpy = cpy->left;
        else if(cpy->val < val)
            cpy = cpy->right;
    }

    TreeNode *newNode = new TreeNode(val);
    if(!prev) return newNode;

    if(prev->val > val)
        prev->left = newNode;
    else
        prev->right = newNode;

    return root;
}

TreeNode *insertRecursive(TreeNode *root, int val) {
    if(!root) {
        return new TreeNode(val);
    } else {
        if(root->val == val)
            return root;
        else if(root->val > val) 
            root->left = insertRecursive(root->left, val);
        else if(root->val < val) 
            root->right = insertRecursive(root->right, val);
    }

    return root;
}

TreeNode *deleteNode(TreeNode *root, int val) {
    if(!root) return nullptr;

    if(root->val > val) {
        root->left = deleteNode(root->left, val);
    } else if(root->val < val) {
        root->right = deleteNode(root->right, val);
    } else {
        int predHeight = getHeight(root->left);
        int succHeight = getHeight(root->right);

        if(predHeight == 0 && succHeight == 0) {
            delete root;
            return nullptr;
        } else if(predHeight > succHeight) {
            TreeNode *pred = inPre(root);
            root->val = pred->val;

            root->left = deleteNode(root->left, pred->val);
        } else {
            TreeNode *succ = inSucc(root);
            root->val = succ->val;

            root->right = deleteNode(root->right, succ->val);
        }
    }

    return root;
}

int main() {
    vector<int> v = {50, 40, 30, 45, 60, 55, 65};
    int idx = 0;

    TreeNode *tree = createFromPreOrder(v, idx, INT_MIN, INT_MAX);
    preOrder(tree);
    cout << endl;

    cout << findValue(tree, 100) << endl;
    insertIterative(tree, 47);
    insertRecursive(tree, 100);

    preOrder(tree);
    cout << endl;

    deleteNode(tree, 50);
    preOrder(tree);
    cout << endl;

    v = {50, 40, 30, 45, 60, 55, 65};
    TreeNode *iterativeCreate = iterativeCreateFromPreOrder(v);
    preOrder(iterativeCreate);
}
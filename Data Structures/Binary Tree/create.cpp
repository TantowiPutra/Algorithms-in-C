#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode (int val, TreeNode *left = nullptr, TreeNode *right = nullptr) {
        this->val   = val;
        this->left  = left;
        this->right = right;
    }
};

void preorderTraversal(TreeNode *root) {
    if(!root) return;
    cout << root->val << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void iterativePreOrderTraversal(TreeNode *root) {
    if(!root)  return;

    stack<TreeNode *> q;

    while(root || !q.empty()) {
        if(root)  {
            cout << root->val << " ";
            q.push(root);
            root = root->left;
        } else {
            root = q.top(); q.pop();
            root = root->right;
        }
    }
}

void morrisTreePreorderTraversal(TreeNode *root) {
    // O(N) TC, O(1) SC
    /*
             1
            / \
           2   3
         /
        4
    */
        
    while(root) {
        if(!root->left) {
            cout << root->val << " ";
            root = root->right;
        } else {
            TreeNode *predecessor = root->left;

            // Find predecessor: Node paling kanan disebelah kiri
            while(predecessor->right && predecessor->right != root)
                predecessor = predecessor->right;

            if(predecessor->right == root) {
                // Putusin Linknya
                predecessor->right = nullptr;

                // Geser Root Node Ke Kanan
                root = root->right;
            } else {
                cout << root->val << " ";
                predecessor->right = root;
                root = root->left;
            }
        }
    }
}

void inOrderTraversal(TreeNode *root) {
    if(!root) return;

    inOrderTraversal(root->left);
    cout << root->val << " ";
    inOrderTraversal(root->right);
}

void morrisInOrderTraversal(TreeNode *root) {
    if(!root) return;

    while(root) {
        if(!root->left) {
            cout << root->val << " ";
            root = root->right;
        } else {
            TreeNode *predecessor = root->left;

            while(predecessor->right && predecessor->right != root)
                predecessor = predecessor->right;

            if(predecessor->right == root) {
                cout << root->val << " ";
                predecessor->right = nullptr;

                root = root->right;
            } else {
                predecessor->right = root;
                root = root->left;
            }
        } 
    }
}

void iterativeInOrderTraversal(TreeNode *root) {
    if(!root) return;

    stack<TreeNode *> s;

    while(root || !s.empty()) {
        if(root) {
            s.push(root);
            root = root->left;
        } else {
            root = s.top(); s.pop();
            cout << root->val << " ";
            root = root->right;
        }
    }
}

void bfs(TreeNode *root) {
    queue<TreeNode *> q;
    if(root) q.push(root);

    while(!q.empty()) {
        TreeNode *front = q.front(); q.pop();

        cout << front->val << " ";
        if(front->left) q.push(front->left);
        if(front->right) q.push(front->right);
    }
}

TreeNode *copyTree(TreeNode *root) {
    if(!root) return nullptr;

    TreeNode *curr = new TreeNode(root->val, nullptr, nullptr);

    curr->left  = copyTree(root->left);
    curr->right = copyTree(root->right);

    return curr;
}

int main() {
    vector<TreeNode *> v;

    int val = 10;
    
    for(int i = 0; i < 10; i++) {
        TreeNode *newNode = new TreeNode(val, nullptr, nullptr);
        val += 10;

        v.push_back(newNode);
    }

    for(int i = 0; i < 10; i++) {
        if(i * 2 + 1 < 10) v[i]->left  = v[i * 2 + 1];
        if(i * 2 + 2 < 10) v[i]->right = v[i * 2 + 2];
    }

    cout << "Recursive Preorder: "; preorderTraversal(v[0]); cout << endl;
    cout << "Iterative Preorder: "; iterativePreOrderTraversal(v[0]); cout << endl;
    cout << "Moris Preorder    : "; morrisTreePreorderTraversal(v[0]); cout << endl;
    cout << "Recursive Inorder : "; inOrderTraversal(v[0]); cout << endl;
    cout << "Iterative Inorder : "; iterativeInOrderTraversal(v[0]); cout << endl;
    cout << "Moris Inorder     : "; morrisInOrderTraversal(v[0]); cout << endl;
    cout << "BFS: "; bfs(v[0]); cout << endl;

    TreeNode *cpy = copyTree(v[0]);
    cout << "Iterative Preorder Tree Copy: "; iterativePreOrderTraversal(cpy); cout << endl;

    return 0;
}
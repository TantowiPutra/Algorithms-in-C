#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int height;
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val, int height, TreeNode *left = nullptr, TreeNode *right = nullptr) : val(val), height(height), left(left), right(right) {}
};

int getHeight(TreeNode *node) {
    return node ? node->height : 0;
}

void updateHeight(TreeNode *node) {
    if(node) node->height = 1 + max(getHeight(node->left), getHeight(node->right));
}

int findSuccessor(TreeNode *node) {
    if(!node) return 0;

    while(node->left)
        node = node->left;

    return node->val;
}

void preOrderTraversal(TreeNode *root) {
    if(!root) 
        return;

    cout << root->val << " " << root->height <<endl;
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

TreeNode *rotateLeft(TreeNode *root) {  
    TreeNode *newRoot = root->right;
    root->right       = newRoot->left;

    newRoot->left = root;

    updateHeight(newRoot->left);
    updateHeight(newRoot);

    return newRoot;
}

TreeNode *rotateRight(TreeNode *root) {
    TreeNode *newRoot = root->left;
    root->left        = newRoot->right;

    newRoot->right = root;

    updateHeight(newRoot->right);
    updateHeight(newRoot);

    return newRoot;
}

TreeNode *insertAVL(TreeNode *root, int val) {
    if(!root)
        return new TreeNode(val, 1);

    if(root->val > val) {
        root->left = insertAVL(root->left, val);
    } else if(root->val < val) {
        root->right = insertAVL(root->right, val);
    } else {
        // CEGAH DUPLICATE
        return root;
    }

    int balanceFactor = getHeight(root->left) - getHeight(root->right);

    // CONDONG KE KIRI (LL)
    if(balanceFactor > 1 && val < root->left->val) {
        // RIGHT ROTATION
        root = rotateRight(root); 
    }

    // CONDONG KE KIRI -> KANAN (LR)
    if(balanceFactor > 1 && val > root->left->val) {
        // LEFT ROTATION
        root->left = rotateLeft(root->left);

        // RIGHT ROTATION
        root = rotateRight(root);
    }

    // CONDONG KE KANAN (RR)
    if(balanceFactor < -1 && val > root->right->val) {
        // LEFT ROTATION
        root = rotateLeft(root); 
    }

    // CONDING KE KANAN KIRI (RL)
    if(balanceFactor < -1 && val < root->right->val) {
        // RIGHT ROTATION
        root->right = rotateRight(root->right);
        
        // LEFT ROTATION
        root = rotateLeft(root);
    }
    
    updateHeight(root);
    return root;
}

TreeNode *deleteAVL(TreeNode *root, int val) {
    if(!root)
        return nullptr;

    if(root->val < val) {
        root->right = deleteAVL(root->right, val);
    } else if(root->val > val) {
        root->left  = deleteAVL(root->left, val);
    } else {
        // KETEMU VALUE DELETE
        if(!root->left || !root->right) {
            TreeNode *temp = root->left ? root->left : root->right;
            if(!temp) {
                // cout << root->val << "Here" << endl; 
                temp = root;
                root = nullptr;
            } else {
                *root = *temp;
            }

            delete temp;
        } else {
            // LEFT / RIGHT LENGKAP
            int successor = findSuccessor(root->right);

            root->val = successor;

            root->right = deleteAVL(root->right, successor);
        }
    }

    if(!root) return root;

    int balanceFactor = getHeight(root->left) - getHeight(root->right);
    // LEFT LEFT
    if(balanceFactor > 1 && getHeight(root->left->left) >= getHeight(root->left->right))
        return rotateRight(root);

    // LEFT RIGHT
    if(balanceFactor > 1 && getHeight(root->left->left) < getHeight(root->left->right)) {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    // RIGHT RIGHT
    if(balanceFactor < -1 && getHeight(root->right->right) >= getHeight(root->right->left))
        return rotateLeft(root);

    // RIGHT LEFT
    if(balanceFactor < -1 && getHeight(root->right->right) < getHeight(root->right->left)) {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    updateHeight(root);
    return root;
}

int main() {
    TreeNode * root = insertAVL(nullptr, 10);
    root = insertAVL(root, 15);
    root = insertAVL(root, 12);

    // preOrderTraversal(root); 

    root = deleteAVL(root, 12);
    preOrderTraversal(root); 

    return 0;
}
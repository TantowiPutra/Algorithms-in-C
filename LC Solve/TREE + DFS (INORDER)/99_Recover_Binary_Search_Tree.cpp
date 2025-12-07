#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode *first = nullptr, *second = nullptr, *prev = nullptr;
    void inOrder(TreeNode* root) {
        if (!root) return;

        inOrder(root->left);

        if (prev && prev->val > root->val) {
            cout << root->val << " " << prev->val << endl;

            if (!first) {
                first = prev;
                second = root;
            } else {
                second = root;
            }
        }
        prev = root;

        inOrder(root->right);
    }

    void morrisTraversal(TreeNode *root) {
        while(root) {
            // KALAU NODE SEKARANG GAK ADA LEFT, LANGSUNG KE KANAN (CURRENT NODE JADI PREV)
            if(!root->left) {
                if(prev && prev->val > root->val) {
                    if(!first) {
                        first = prev;
                        second = root;
                    } else {
                        second = root;
                    }
                }

                prev = root;
                root = root->right;
            } else {
                // CARI PREDECESSOR UNTUK BUAT JALUR BALIK KE ROOT
                TreeNode *pred = root->left;
                while(pred->right && pred->right != root) {
                    pred = pred->right;
                }

                if(!pred->right) {
                    pred->right = root;
                    root = root->left;
                } else {
                    if(prev && prev->val > root->val) {
                        if(!first) {
                            first = prev;
                            second = root;
                        } else {
                            second = root;
                        }
                    }
                    
                    // DARI BAWAH, RECURSE BALIK KE ATAS
                    pred->right = nullptr;
                    prev = root;

                    root = root->right;
                }
            }
        }
    }

    void recoverTree(TreeNode* root) {
        morrisTraversal(root);

        // inOrder(root);
        swap(first->val, second->val);
    }
};

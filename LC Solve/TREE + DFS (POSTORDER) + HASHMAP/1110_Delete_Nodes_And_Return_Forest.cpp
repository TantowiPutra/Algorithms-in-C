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
    unordered_set<int> set;
    TreeNode *dfs(TreeNode *root, TreeNode *parent, vector<TreeNode *> &res) {
        if(!root) return nullptr;

        TreeNode *rootCpy = root;
        TreeNode *left    = root->left;
        TreeNode *right   = root->right;  

        if(set.count(root->val)) root = nullptr;
        else if(!parent) res.push_back(root);

        rootCpy->left  = dfs(rootCpy->left,  root, res);
        rootCpy->right = dfs(rootCpy->right, root, res); 

        return root;
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode *> res;
        set.insert(to_delete.begin(), to_delete.end());

        dfs(root, nullptr, res);

        return res;
    }
};
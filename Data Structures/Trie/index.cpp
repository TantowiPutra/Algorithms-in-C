// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

class TrieNode {
    public:
        TrieNode *children[26];
        bool isLeaf;
        
        TrieNode() {
            isLeaf = false;
            for(int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
        }
        
        static void insert(TrieNode *root, const string &key) {
            TrieNode *curr = root;
            
            for(char c : key) {
                if(!curr->children[c - 'a']) {
                    TrieNode *newNode = new TrieNode();
                    curr->children[c - 'a'] = newNode;
                }
                
                curr = curr->children[c - 'a'];
            }
            
            curr->isLeaf = true;
        }
        
        static bool search(TrieNode *root, const string &key) {
            if(!root) return false;
            
            TrieNode *curr = root;
            for(char c : key) {
                if(!curr->children[c - 'a']) 
                    return false;
                    
                curr = curr->children[c - 'a'];
            }
            
            return curr->isLeaf;
        }
        
        static bool isPrefix(TrieNode *root, const string &key) {
            if(!root) return false;
            
            TrieNode *curr = root;
            for(char c : key) {
                if(!curr->children[c - 'a'])
                    return false;
                    
                curr = curr->children[c - 'a'];
            }
            
            return true;
        }
};

int main() {
    TrieNode *root = new TrieNode();
    vector<string> arr = {"and", "ant", "do", "dad"};
    
    for(auto str : arr) {
        TrieNode::insert(root, str);
    }
    
    vector<string> searchKeys = {"do", "gee", "bat"};
    for (string &s : searchKeys){
        if(TrieNode::search(root, s))
            cout << "true ";
        else
            cout << "false ";
    } 
    cout << endl;
    
    vector<string> prefixKeys = {"ge", "ba", "do", "da"};
    for (string &s : prefixKeys){
        if (TrieNode::isPrefix(root, s))
            cout << "true ";
        else
            cout << "false ";
    }
    cout << endl;

    return 0;
}
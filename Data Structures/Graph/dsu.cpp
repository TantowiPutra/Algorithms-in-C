#include <bits/stdc++.h>
using namespace std;
// DSU FOR GRAPH CYCLE DETECTION
class DSU {
    public:
        vector<int> v;
        DSU(int n) {
            this->v.resize(n);
            for(int i = 0; i < n; i++) this->v[i] = -1;
        }

        pair<int, int> find(int x) {
            int root = x;
            while(this->v[root] >= 0)
                root = this->v[root]; // Path Compression, agar amortized O(1), kalo ga gini worse case setiap check parent bisa jadi O(N)

            while(this->v[x] >= 0) {
                int p = this->v[x];
                this->v[x] = root;
                x     = p;
            }

            return {root, this->v[root]};
        }

        bool merge(int x, int y) {
            auto [pX, szX] = find(x);
            auto [pY, szY] = find(y);
            
            if(pX == pY) return false;
            
            // cout << pX << " " << pY << szX << " " << szY;
            if(szX > szY) { // Himpunan Y Lebih Besar 
                swap(szX, szY);
                swap(pX, pY);
            }
                
            this->v[pY]  = pX;
            this->v[pX] += szY;

            return true;
        }
};

int main() {
    vector<unordered_set<int>> adj_list = {
        {1, 3},
        {0, 2, 3},
        {1, 3},
        {2, 1},
    };

    int n = adj_list.size();
    DSU dsu(n);

    // dsu.find(0);
    // dsu.merge(0, 1);
    for(int i = 0; i < n; i++) {
        for(int node : adj_list[i]) {
            if(i < node) {
                if(!dsu.merge(i, node)) {
                    cout << "Cycle Detected!" << endl;   
                }
            }
        }
    }

    return 0;
}
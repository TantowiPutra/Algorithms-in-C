#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dfs(int current, int parent, vector<vector<int>> &adjList, vector<int> &nodeValues, int k, int &cnt) {
        int sum = 0;

        for (int adj : adjList[current]) {
            if(adj != parent) {
                sum += dfs(adj, current, adjList, nodeValues, k, cnt) % k;
            }
        }

        sum += nodeValues[current];

        sum %= k;
        if(sum % k == 0) cnt++;

        return sum;
    }

    int bfs(int n, vector<vector<int>> &edges, vector<int> &values, int k) {
        // 1. Inisialisasi Graph, yakni map Tiap node dengan seluruh node yang terhubung
        unordered_map<int, unordered_set<int>> g;

        for(auto &edge : edges) {
            g[edge[0]].insert(edge[1]);
            g[edge[1]].insert(edge[0]);
        }

        // 2. Proses Node dari Leaf Node, yakni Node yang hanya terhubung ke 1 Node Max
        queue<int> q;
        for(auto &p : g) {
            int curr = p.first;
            auto &adj = p.second;

            if(adj.size() == 1) {
                q.push(curr);
            }
        }


        // while(!q.empty()) {
        //     int front = q.front(); q.pop();

        //     cout << front << " ";
        // }

        int cnt = 0;
        // 3. Mulai proses leaf node
        while(!q.empty()) {
            int front = q.front(); q.pop();

            // ! kalo gak ada node lain lagi yg terhubung -> node satu"nya -> jadi 1 komponen
            if(g[front].size() == 0) {
                cnt++;
                break;
            }

            // Ambil Node Adjacent, Gaperlu check krna udah pasti leaf
            int adj   = *g[front].begin();

            // Hapus Edge diantara kedua node
            g[front].erase(adj);
            g[adj].erase(front);

            if(values[front] % k == 0) {
                cnt++; // krna habis dibagi k, maka jadi tree kepisah
            } else {
                // kalo gak bisa habis dibagi tiga, merge value sekarang dengan parentnya
                values[adj] = (values[adj] + values[front]) % k; // mod dengan k, cegah overflow
            }

            // Kalo jadi leaf node, tambahin ke queue
            if(g[adj].size() == 1) q.push(adj);
        }

        return cnt;
    }

    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        if(n < 2) return 1;

        return bfs(n, edges, values, k);

        vector<vector<int>> adjList(n);

        for(auto edge: edges) {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }

        int cnt = 0;
        dfs(0, -1, adjList, values, k, cnt);
        
        return cnt;
    }
};

int main() {
    int n = 5, k = 6, cnt = 0; 
    vector<vector<int>> edges = { {0,2}, {1,2}, {1,3}, {2,4}};
    vector<int> values = {1,8,1,5,4};

    vector<vector<int>> adjList(n);

    for(auto edge: edges) {
        adjList[edge[0]].push_back(edge[1]);
        adjList[edge[1]].push_back(edge[0]);
    }

    Solution s = Solution();
    s.dfs(2, -1, adjList, values, k, cnt);
    cout << cnt;

    return 0;
}
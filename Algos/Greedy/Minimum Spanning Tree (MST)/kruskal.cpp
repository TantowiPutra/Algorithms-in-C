#include <bits/stdc++.h>
using namespace std;

class DSU {
    private:
        int find(int node) {
            int root = node;
            while(this->v[root] >= 0) {
                root = v[root];
            }

            while(this->v[node] >= 0) {
                int p   = v[node];
                v[node] = root;
                node    = p;
            }

            return root;
        }

    public:
        vector<int> v;
        DSU(int n) {
            v.assign(n + 1, -1);
        }

        bool unite(int node1, int node2) {
            int p1 = find(node1);
            int p2 = find(node2);

            if(p1 == p2) return false;

            if(this->v[p1] > this->v[p2])
                swap(p1, p2);

            this->v[p1] += this->v[p2];
            this->v[p2]  = p1;

            return true;
        }
};

void kruskalSort(vector<tuple<int, int, int>> adj_list, int n) {
    DSU dsu = DSU(n);
    auto cmp = [](auto a, auto b) {
        return get<2>(a) < get<2>(b);
    };

    sort(adj_list.begin(), adj_list.end(), cmp);

    int totalCost = 0;
    for(auto a : adj_list) {
        int source = get<0>(a), target = get<1>(a), w = get<2>(a);

        if(dsu.unite(source, target)) {
            totalCost += w;
        }
    }

    cout << "Minimum Spanning Tree Sort: " << totalCost << endl;
}

void kruskalHeap(vector<tuple<int, int, int>> adj_list, int n) {
    DSU dsu = DSU(n);
    auto cmp = [](auto a, auto b) {
        return get<2>(a) > get<2>(b);
    };

    priority_queue<
        tuple<int, int, int>,
        vector<tuple<int, int, int>>,
        decltype(cmp)
    > pq(cmp);

    for(auto a : adj_list) {
        pq.push(a);
    }

    int totalCost = 0;
    while(!pq.empty()) {
        tuple<int, int, int> top = pq.top(); pq.pop();
        int source = get<0>(top), target = get<1>(top), w = get<2>(top);
        
        if(dsu.unite(source, target)) {
            totalCost += w;
        }
    }

    cout << "Minimum Spanning Tree PQ: " << totalCost << endl;
}

int main() {
    vector<tuple<int, int, int>> adj_list = {
        {1, 2, 28},
        {1, 6, 10},
        {2, 3, 16},
        {2, 7, 14},
        {3, 4, 12},
        {4, 5, 22},
        {4, 7, 18},
        {5, 6, 25},
        {5, 7, 24}
    };
    
    int n = 7;
    kruskalSort(adj_list, n);
    kruskalHeap(adj_list, n);

    return 0;
}
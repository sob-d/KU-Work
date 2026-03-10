#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, w;
    bool operator<(const Edge& other) const {
        return w < other.w;
    }
};

struct DSU {
    vector<int> parent;
    int components;
    DSU(int n) {
        parent.resize(n + 1);
        for (int i = 1; i <= n; i++) parent[i] = i;
        components = n;
    }
    int find(int i) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent[i]);
    }
    bool unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            parent[root_i] = root_j;
            components--;
            return true;
        }
        return false;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, W;
    if (!(cin >> N >> W)) return 0;

    vector<Edge> all_edges;

    for (int i = 0; i < W; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        
        Edge new_edge = {u, v, w};

        auto it = lower_bound(all_edges.begin(), all_edges.end(), new_edge);
        all_edges.insert(it, new_edge);

        DSU dsu(N);
        int mst_weight = 0;
        int edges_count = 0;
        vector<Edge> next_round_edges;

        for (const auto& edge : all_edges) {
            if (dsu.unite(edge.u, edge.v)) {
                mst_weight += edge.w;
                edges_count++;
                next_round_edges.push_back(edge);
            } else {
                next_round_edges.push_back(edge);
            }
        }

        if (edges_count == N - 1) {
            cout << mst_weight << "\n";
        } else {
            cout << "-1\n";
        }
        
        all_edges = next_round_edges;
    }

    return 0;
}
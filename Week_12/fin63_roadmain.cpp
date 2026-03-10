#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, cost;
    bool operator<(const Edge& other) const {
        return cost < other.cost;
    }
};

struct DSU {
    vector<int> parent;
    int num_sets;
    
    DSU(int n) {
        parent.resize(n + 1);
        for (int i = 1; i <= n; i++) parent[i] = i;
        num_sets = n;
    }
    
    int find_set(int v) {
        if (v == parent[v]) return v;
        return parent[v] = find_set(parent[v]);
    }
    
    void unite(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            parent[b] = a;
            num_sets--;
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    if (!(cin >> N >> M)) return 0;

    vector<Edge> edges;
    for (int i = 0; i < M; i++) {
        int u, v, c, d;
        cin >> u >> v >> c >> d;
        int weight = (d == 1) ? 0 : c;
        edges.push_back({u, v, weight});
    }

    sort(edges.begin(), edges.end());

    DSU dsu(N);
    long long total_cost = 0;

    for (const auto& edge : edges) {
        if (dsu.find_set(edge.u) != dsu.find_set(edge.v)) {
            dsu.unite(edge.u, edge.v);
            total_cost += edge.cost;
        }
    }

    if (dsu.num_sets == 1) {
        cout << total_cost << endl;
    } else {
        cout << -1 << endl; 
    }

    return 0;
}
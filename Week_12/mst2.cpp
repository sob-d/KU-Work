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

const int MAX_N = 100005;
int parent[MAX_N];

int find_set(int v) {
    if (v == parent[v]) return v;
    return parent[v] = find_set(parent[v]);
}

bool unite_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        parent[b] = a;
        return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<Edge> edges;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    sort(edges.begin(), edges.end());

    for (int i = 1; i <= n; i++) parent[i] = i;

    long long mst_weight = 0;
    int edges_count = 0;

    for (const auto& edge : edges) {
        if (unite_sets(edge.u, edge.v)) {
            mst_weight += edge.w;
            edges_count++;
            if (edges_count == n - 1) break;
        }
    }

    cout << mst_weight << endl;

    return 0;
}
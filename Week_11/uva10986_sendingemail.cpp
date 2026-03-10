#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const long long INF = 1e18;

void solve(int caseNum) {
    int n, m, s, t;
    cin >> n >> m >> s >> t;

    vector<pair<int, int>> adj[n];
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<long long> dist(n, INF);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

    dist[s] = 0;
    pq.push({0, s});

    while (!pq.empty()) {
        long long d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue;
        if (u == t) break;

        for (auto &edge : adj[u]) {
            int v = edge.first;
            int w = edge.second;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    cout << "Case #" << caseNum << ": ";
    if (dist[t] == INF) cout << "unreachable" << endl;
    else cout << dist[t] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int numCases;
    cin >> numCases;
    for (int i = 1; i <= numCases; i++) {
        solve(i);
    }
    return 0;
}
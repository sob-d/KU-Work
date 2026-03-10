#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const long long INF = 1e18;

struct Node {
    int u, state;
    long long w;
    bool operator>(const Node& o) const { return w > o.w; }
};

void solve() {
    int c, v;
    while (cin >> c >> v) {
        vector<pair<int, int>> adj[c + 1];
        for (int i = 0; i < v; i++) {
            int c1, c2, g;
            cin >> c1 >> c2 >> g;
            adj[c1].push_back({c2, g});
            adj[c2].push_back({c1, g});
        }

        vector<vector<long long>> dist(c + 1, vector<long long>(2, INF));
        priority_queue<Node, vector<Node>, greater<Node>> pq;

        dist[1][0] = 0;
        pq.push({1, 0, 0});

        while (!pq.empty()) {
            Node curr = pq.top();
            pq.pop();

            if (curr.w > dist[curr.u][curr.state]) continue;

            for (auto& edge : adj[curr.u]) {
                int next_u = edge.first;
                int weight = edge.second;
                int next_state = 1 - curr.state;

                if (dist[curr.u][curr.state] + weight < dist[next_u][next_state]) {
                    dist[next_u][next_state] = dist[curr.u][curr.state] + weight;
                    pq.push({next_u, next_state, dist[next_u][next_state]});
                }
            }
        }

        if (dist[c][0] == INF) cout << -1 << endl;
        else cout << dist[c][0] << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
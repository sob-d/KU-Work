#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

const int INF = 1e9;

// ทิศทางการเดิน: ขึ้น, ลง, ซ้าย, ขวา
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};
int energy_cost[] = {5, 0, 1, 1};

struct Node {
    int r, c, w;
    bool operator>(const Node& o) const { return w > o.w; }
};

int main() {
    int H, W;
    if (!(cin >> H >> W)) return 0;

    vector<string> grid(H);
    for (int i = 0; i < H; i++) cin >> grid[i];

    vector<vector<int>> dist(H, vector<int>(W, INF));
    priority_queue<Node, vector<Node>, greater<Node>> pq;

    int start_r = H - 1, start_c = 0;
    if (grid[start_r][start_c] == '.') {
        dist[start_r][start_c] = 0;
        pq.push({start_r, start_c, 0});
    }

    while (!pq.empty()) {
        Node curr = pq.top();
        pq.pop();

        if (curr.w > dist[curr.r][curr.c]) continue;
        
        if (curr.r == 0 && curr.c == W - 1) {
            cout << curr.w << endl;
            return 0;
        }

        for (int i = 0; i < 4; i++) {
            int nr = curr.r + dr[i];
            int nc = curr.c + dc[i];

            if (nr >= 0 && nr < H && nc >= 0 && nc < W && grid[nr][nc] == '.') {
                if (dist[curr.r][curr.c] + energy_cost[i] < dist[nr][nc]) {
                    dist[nr][nc] = dist[curr.r][curr.c] + energy_cost[i];
                    pq.push({nr, nc, dist[nr][nc]});
                }
            }
        }
    }

    cout << -1 << endl;
    return 0;
}
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Point {
    int x, y;
};

int N, R;
vector<Point> points;
vector<int> adj[1005];
int dist[1005];

// ฟังก์ชันเช็คระยะทางยกกำลังสอง เพื่อเลี่ยงการใช้ sqrt
bool can_jump(Point a, Point b) {
    int dx = a.x - b.x;
    int dy = a.y - b.y;
    return (dx * dx + dy * dy) <= (R * R);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> R;

    // เพิ่มจุดเริ่มต้น (0,0) เป็นจุดแรก (index 0)
    points.push_back({0, 0});
    
    for (int i = 0; i < N; i++) {
        int tx, ty;
        cin >> tx >> ty;
        points.push_back({tx, ty});
    }

    // เพิ่มจุดสิ้นสุด (100,100) เป็นจุดสุดท้าย
    points.push_back({100, 100});

    int total_points = points.size();

    // สร้าง Adjacency List โดยเช็คทุกคู่จุด
    for (int i = 0; i < total_points; i++) {
        dist[i] = -1; // เริ่มต้นให้ระยะทางเป็น -1 (unvisited)
        for (int j = i + 1; j < total_points; j++) {
            if (can_jump(points[i], points[j])) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    // เริ่ม BFS จากจุด index 0 (0,0)
    queue<int> q;
    q.push(0);
    dist[0] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        // ถ้าถึงจุดสุดท้าย (100,100)
        if (u == total_points - 1) {
            cout << dist[u] << endl;
            return 0;
        }

        for (int v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    // ถ้าออกจาก loop โดยไม่พบคำตอบ
    cout << -1 << endl;

    return 0;
}
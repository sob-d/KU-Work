# 🔵 Graph Algorithm — C++ Guide

> **Graph** คือโครงสร้างข้อมูลที่ประกอบด้วย **Node (Vertex)** และ **Edge** เชื่อมระหว่างกัน  
> ใช้แทนสิ่งต่างๆ เช่น แผนที่, เครือข่าย, ความสัมพันธ์

---

## 📌 ประเภทของ Graph

| ประเภท | ความหมาย |
|---|---|
| Undirected | เส้นเชื่อมสองทิศทาง |
| Directed (Digraph) | เส้นเชื่อมทิศทางเดียว |
| Weighted | มีน้ำหนักบน edge |
| Unweighted | ไม่มีน้ำหนัก |
| DAG | Directed Acyclic Graph (ไม่มีวงจร) |

---

## 🏗️ การสร้าง Graph (Representation)

### 1. Adjacency List ⭐ (แนะนำ — ใช้บ่อยที่สุด)

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;       // n = จำนวน node, m = จำนวน edge
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);   // index 1-based

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);          // undirected: ใส่ทั้งสองทาง
        adj[v].push_back(u);
    }
}
```

**Weighted Graph:**
```cpp
vector<vector<pair<int,int>>> adj(n + 1);  // {neighbor, weight}

for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
}
```

---

### 2. Adjacency Matrix (ใช้เมื่อ n เล็ก ≤ 1000)

```cpp
int mat[1001][1001] = {};

for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    mat[u][v] = 1;
    mat[v][u] = 1;   // undirected
}
```

---

### 3. Edge List (ใช้กับ Kruskal / Bellman-Ford)

```cpp
struct Edge {
    int u, v, w;
};

vector<Edge> edges(m);
for (auto& [u, v, w] : edges) cin >> u >> v >> w;
```

---

## 🔍 Traversal

---

### BFS — Breadth First Search

> ค้นหาแบบกว้างก่อน ใช้ **queue**  
> ✅ หาระยะทางสั้นสุด (Unweighted), Level order

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> dist(n + 1, -1);   // -1 = ยังไม่เยี่ยม
    queue<int> q;

    int start = 1;
    dist[start] = 0;
    q.push(start);

    while (!q.empty()) {
        int cur = q.front(); q.pop();

        for (int next : adj[cur]) {
            if (dist[next] == -1) {
                dist[next] = dist[cur] + 1;
                q.push(next);
            }
        }
    }

    // dist[i] = ระยะทางสั้นสุดจาก start ถึง i
    for (int i = 1; i <= n; i++) cout << dist[i] << " ";
    cout << "\n";
}
```

---

### DFS — Depth First Search

> ค้นหาแบบลึกก่อน ใช้ **recursion** หรือ **stack**  
> ✅ หา connected component, cycle detection, topological sort

**แบบ Recursive:**
```cpp
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;

void dfs(int u) {
    visited[u] = true;
    cout << u << " ";    // process node

    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    adj.assign(n + 1, {});
    visited.assign(n + 1, false);

    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1);   // เริ่มจาก node 1
}
```

**แบบ Iterative (Stack) — ป้องกัน stack overflow:**
```cpp
void dfs(int start) {
    stack<int> st;
    st.push(start);
    visited[start] = true;

    while (!st.empty()) {
        int cur = st.top(); st.pop();
        cout << cur << " ";

        for (int v : adj[cur]) {
            if (!visited[v]) {
                visited[v] = true;
                st.push(v);
            }
        }
    }
}
```

---

### นับ Connected Components

```cpp
int components = 0;
for (int i = 1; i <= n; i++) {
    if (!visited[i]) {
        dfs(i);          // หรือ bfs(i)
        components++;
    }
}
cout << components << "\n";
```

---

## 🛣️ Shortest Path

---

### Dijkstra — Single Source Shortest Path (Weighted, Non-negative)

> ✅ หาเส้นทางสั้นสุดจาก source ถึงทุก node  
> ⚠️ ใช้ไม่ได้ถ้า weight เป็นลบ

```cpp
#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;      // {dist, node}
const int INF = 1e9;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pii>> adj(n + 1);    // {neighbor, weight}
    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});      // ลบออกถ้า directed
    }

    vector<int> dist(n + 1, INF);
    priority_queue<pii, vector<pii>, greater<pii>> pq;   // min-heap

    int src = 1;
    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();

        if (d > dist[u]) continue;     // outdated entry — ข้ามเลย

        for (auto [v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << (dist[i] == INF ? -1 : dist[i]) << " ";
    }
    cout << "\n";
}
```

---

### Bellman-Ford — Shortest Path (รับ weight ลบได้)

> ✅ ตรวจ **Negative Cycle** ได้  
> ⏱️ O(V × E) — ช้ากว่า Dijkstra

```cpp
#include <bits/stdc++.h>
using namespace std;

struct Edge { int u, v, w; };

int main() {
    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);
    for (auto& [u, v, w] : edges) cin >> u >> v >> w;

    const int INF = 1e9;
    vector<int> dist(n + 1, INF);
    dist[1] = 0;

    // Relax n-1 รอบ
    for (int i = 0; i < n - 1; i++) {
        for (auto& [u, v, w] : edges) {
            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    // ตรวจ negative cycle (รอบที่ n)
    bool hasNegCycle = false;
    for (auto& [u, v, w] : edges) {
        if (dist[u] != INF && dist[u] + w < dist[v]) {
            hasNegCycle = true;
        }
    }

    if (hasNegCycle) cout << "Negative cycle detected!\n";
    else for (int i = 1; i <= n; i++) cout << dist[i] << " ";
}
```

---

### Floyd-Warshall — All Pairs Shortest Path

> ✅ หาระยะสั้นสุดระหว่างทุกคู่ node  
> ⏱️ O(V³) — ใช้กับ n ≤ 500

```cpp
#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int dist[501][501];

int main() {
    int n, m;
    cin >> n >> m;

    // Init
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            dist[i][j] = (i == j) ? 0 : INF;

    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        dist[u][v] = min(dist[u][v], w);
        dist[v][u] = min(dist[v][u], w);
    }

    // Floyd-Warshall
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (dist[i][k] != INF && dist[k][j] != INF)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
}
```

---

## 🌲 Minimum Spanning Tree (MST)

---

### Kruskal's Algorithm

> ✅ เลือก edge น้ำหนักน้อยสุดทีละเส้น โดยไม่ให้เกิด cycle  
> ใช้ **DSU (Disjoint Set Union)** ตรวจ cycle

```cpp
#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> parent, rank_;
    DSU(int n) : parent(n+1), rank_(n+1, 0) {
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x) {
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }
    bool unite(int x, int y) {
        x = find(x); y = find(y);
        if (x == y) return false;
        if (rank_[x] < rank_[y]) swap(x, y);
        parent[y] = x;
        if (rank_[x] == rank_[y]) rank_[x]++;
        return true;
    }
};

struct Edge { int u, v, w; };

int main() {
    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);
    for (auto& [u, v, w] : edges) cin >> u >> v >> w;

    // เรียง edge ตาม weight
    sort(edges.begin(), edges.end(), [](auto& a, auto& b) {
        return a.w < b.w;
    });

    DSU dsu(n);
    long long totalWeight = 0;
    int edgeCount = 0;

    for (auto& [u, v, w] : edges) {
        if (dsu.unite(u, v)) {
            totalWeight += w;
            edgeCount++;
            if (edgeCount == n - 1) break;
        }
    }

    cout << totalWeight << "\n";
}
```

---

### Prim's Algorithm

> ✅ เหมาะกับ dense graph (edge เยอะ)

```cpp
#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pii>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }

    vector<bool> inMST(n + 1, false);
    priority_queue<pii, vector<pii>, greater<pii>> pq;   // {weight, node}
    long long totalWeight = 0;

    pq.push({0, 1});

    while (!pq.empty()) {
        auto [w, u] = pq.top(); pq.pop();

        if (inMST[u]) continue;
        inMST[u] = true;
        totalWeight += w;

        for (auto [ww, v] : adj[u]) {
            if (!inMST[v]) pq.push({ww, v});
        }
    }

    cout << totalWeight << "\n";
}
```

---

## 🔄 Cycle Detection

### Undirected Graph — DFS
```cpp
bool hasCycle(int u, int parent) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            if (hasCycle(v, u)) return true;
        } else if (v != parent) {
            return true;    // เจอ back edge → มี cycle
        }
    }
    return false;
}
```

### Directed Graph — DFS + recursion stack
```cpp
vector<bool> visited, inStack;

bool hasCycle(int u) {
    visited[u] = inStack[u] = true;
    for (int v : adj[u]) {
        if (!visited[v] && hasCycle(v)) return true;
        if (inStack[v]) return true;
    }
    inStack[u] = false;
    return false;
}
```

---

## 📋 Topological Sort

> ใช้กับ **DAG** — เรียง node ตามลำดับความสัมพันธ์  
> ✅ job scheduling, task dependency

### Kahn's Algorithm (BFS)
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    vector<int> indegree(n + 1, 0);

    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        indegree[v]++;
    }

    queue<int> q;
    for (int i = 1; i <= n; i++)
        if (indegree[i] == 0) q.push(i);

    vector<int> order;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        order.push_back(u);

        for (int v : adj[u]) {
            indegree[v]--;
            if (indegree[v] == 0) q.push(v);
        }
    }

    if ((int)order.size() != n) cout << "Graph has a cycle!\n";
    else for (int x : order) cout << x << " ";
    cout << "\n";
}
```

### DFS-based Topological Sort
```cpp
vector<bool> visited;
vector<int> order;

void dfs(int u) {
    visited[u] = true;
    for (int v : adj[u])
        if (!visited[v]) dfs(v);
    order.push_back(u);     // push หลังเยี่ยมลูกหมด
}

// เรียกทุก node แล้ว reverse
for (int i = 1; i <= n; i++)
    if (!visited[i]) dfs(i);

reverse(order.begin(), order.end());
```

---

## 🔗 DSU — Disjoint Set Union (Union-Find)

> ✅ ตรวจว่า node อยู่ใน component เดียวกันไหม  
> ✅ ใช้กับ Kruskal, connectivity problems

```cpp
struct DSU {
    vector<int> parent, rank_;

    DSU(int n) : parent(n + 1), rank_(n + 1, 0) {
        iota(parent.begin(), parent.end(), 0);  // parent[i] = i
    }

    int find(int x) {
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }

    bool unite(int x, int y) {
        x = find(x); y = find(y);
        if (x == y) return false;
        if (rank_[x] < rank_[y]) swap(x, y);
        parent[y] = x;
        if (rank_[x] == rank_[y]) rank_[x]++;
        return true;
    }

    bool connected(int x, int y) {
        return find(x) == find(y);
    }
};

// การใช้งาน
DSU dsu(n);
dsu.unite(1, 2);
dsu.unite(2, 3);
cout << dsu.connected(1, 3) << "\n";    // 1 (true)
cout << dsu.connected(1, 4) << "\n";    // 0 (false)
```

---

## ⭐ SCC — Strongly Connected Components

> ✅ Directed graph: หากลุ่ม node ที่ถึงกันได้ทุกคู่  
> ใช้ **Kosaraju's** หรือ **Tarjan's Algorithm**

### Kosaraju's Algorithm
```cpp
#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> adj, radj;
vector<bool> visited;
vector<int> order;

void dfs1(int u) {
    visited[u] = true;
    for (int v : adj[u])
        if (!visited[v]) dfs1(v);
    order.push_back(u);
}

void dfs2(int u) {
    visited[u] = true;
    for (int v : radj[u])
        if (!visited[v]) dfs2(v);
}

int main() {
    cin >> n >> m;
    adj.assign(n + 1, {});
    radj.assign(n + 1, {});

    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        radj[v].push_back(u);
    }

    visited.assign(n + 1, false);
    for (int i = 1; i <= n; i++)
        if (!visited[i]) dfs1(i);

    visited.assign(n + 1, false);
    int scc = 0;
    while (!order.empty()) {
        int u = order.back(); order.pop_back();
        if (!visited[u]) {
            dfs2(u);
            scc++;
        }
    }

    cout << scc << " SCCs\n";
}
```

---

## 🌉 Bridges & Articulation Points

> **Bridge**: Edge ที่ถ้าเอาออก graph จะแตกออกเป็นสองส่วน  
> **Articulation Point**: Node ที่ถ้าเอาออก graph จะแตก

```cpp
#include <bits/stdc++.h>
using namespace std;

int n, m, timer_ = 0;
vector<vector<int>> adj;
vector<int> disc, low;
vector<bool> visited;
vector<pair<int,int>> bridges;

void dfs(int u, int parent) {
    visited[u] = true;
    disc[u] = low[u] = timer_++;
    int children = 0;

    for (int v : adj[u]) {
        if (!visited[v]) {
            children++;
            dfs(v, u);
            low[u] = min(low[u], low[v]);

            if (low[v] > disc[u])
                bridges.push_back({u, v});

        } else if (v != parent) {
            low[u] = min(low[u], disc[v]);
        }
    }
}

int main() {
    cin >> n >> m;
    adj.assign(n + 1, {});
    disc.assign(n + 1, 0);
    low.assign(n + 1, 0);
    visited.assign(n + 1, false);

    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; i++)
        if (!visited[i]) dfs(i, -1);

    cout << "Bridges: " << bridges.size() << "\n";
}
```

---

## 🎨 Bipartite Check — ตรวจ Graph สองฝั่ง

> **Bipartite Graph** คือ graph ที่สามารถแบ่ง node ออกเป็น **2 กลุ่ม** โดยทุก edge เชื่อมระหว่างกลุ่มเท่านั้น (ไม่มี edge ภายในกลุ่มเดียวกัน)  
> ✅ เทียบเท่ากับ: graph ไม่มี **cycle ความยาวคี่**

### วิธีตรวจ — BFS 2-coloring (แนะนำ)

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> color(n + 1, -1);   // -1 = ยังไม่ระบายสี
    bool isBipartite = true;

    // ตรวจทุก component (graph อาจไม่ connected)
    for (int start = 1; start <= n && isBipartite; start++) {
        if (color[start] != -1) continue;

        queue<int> q;
        q.push(start);
        color[start] = 0;           // ระบายสี 0

        while (!q.empty() && isBipartite) {
            int u = q.front(); q.pop();

            for (int v : adj[u]) {
                if (color[v] == -1) {
                    color[v] = 1 - color[u];    // สลับสี 0 ↔ 1
                    q.push(v);
                } else if (color[v] == color[u]) {
                    isBipartite = false;        // เจอสีเดียวกัน → ไม่ใช่ bipartite
                }
            }
        }
    }

    cout << (isBipartite ? "YES" : "NO") << "\n";

    // แสดงสองกลุ่ม (ถ้าเป็น bipartite)
    if (isBipartite) {
        cout << "Group 0: ";
        for (int i = 1; i <= n; i++) if (color[i] == 0) cout << i << " ";
        cout << "\nGroup 1: ";
        for (int i = 1; i <= n; i++) if (color[i] == 1) cout << i << " ";
        cout << "\n";
    }
}
```

### วิธีตรวจ — DFS (alternative)

```cpp
vector<int> color(n + 1, -1);
bool isBipartite = true;

function<void(int, int)> dfs = [&](int u, int c) {
    color[u] = c;
    for (int v : adj[u]) {
        if (color[v] == -1) {
            dfs(v, 1 - c);
        } else if (color[v] == c) {
            isBipartite = false;
        }
    }
};

for (int i = 1; i <= n; i++)
    if (color[i] == -1) dfs(i, 0);
```

### ตัวอย่าง

```
Input graph:          Bipartite?
1 - 2 - 3 - 4         YES  →  {1,3} และ {2,4}
    |       |
    +---5---+

1 - 2 - 3             NO   →  มี cycle 1-2-3-1 (ความยาว 3 = คี่)
 \_____/
```

> ⚠️ **หมายเหตุ**: ถ้า graph มี **self-loop** → ไม่ใช่ bipartite ทันที

---

## 🧠 เลือก Algorithm ไหนดี?

| โจทย์ | Algorithm |
|---|---|
| ระยะสั้นสุด (unweighted) | BFS |
| ระยะสั้นสุด (weighted, ≥0) | Dijkstra |
| ระยะสั้นสุด (weight ลบได้) | Bellman-Ford |
| ระยะสั้นสุดทุกคู่ | Floyd-Warshall |
| MST (sparse graph) | Kruskal |
| MST (dense graph) | Prim |
| Cycle detection | DFS |
| Topological sort | Kahn's (BFS) / DFS |
| Connected components | DFS / BFS / DSU |
| SCC | Kosaraju / Tarjan |
| Bridge / Articulation | Tarjan (low-disc) |
| Bipartite check | BFS 2-coloring / DFS |

---

## ⚡ Tips สำคัญ

- ใช้ `1-based index` เสมอเพื่อลด bug
- **Undirected**: เพิ่ม edge ทั้งสองทิศทาง
- **Directed**: เพิ่ม edge ทิศทางเดียว
- ใช้ `long long` เมื่อ weight × node อาจเกิน `2×10⁹`
- `const int INF = 1e9` สำหรับ shortest path init
- DFS recursive อาจ stack overflow ถ้า n > 10⁵ → ใช้ iterative
- Dijkstra ต้องเช็ค `if (d > dist[u]) continue;` ทุกครั้ง

---

## 🗂️ สรุป Time Complexity

| Algorithm | Time | Space |
|---|---|---|
| BFS / DFS | O(V + E) | O(V) |
| Dijkstra | O((V + E) log V) | O(V) |
| Bellman-Ford | O(V × E) | O(V) |
| Floyd-Warshall | O(V³) | O(V²) |
| Kruskal | O(E log E) | O(V) |
| Prim | O((V + E) log V) | O(V) |
| DSU (find/unite) | O(α(V)) ≈ O(1) | O(V) |
| Kosaraju SCC | O(V + E) | O(V) |
| Bridges/AP | O(V + E) | O(V) |
| Topo Sort | O(V + E) | O(V) |
| Bipartite Check | O(V + E) | O(V) |
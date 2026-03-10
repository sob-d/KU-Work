#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX_N = 100010;

int n, m;
vector<int> adj[MAX_N];
bool seen[MAX_N];

void read_input() {
    // รับค่า N (จุดยอด) และ M (เส้นเชื่อม)
    if (!(cin >> n >> m)) return;
    
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        // ปรับเป็น 1-based index ตามโจทย์ หรือ 0-based ก็ได้แต่ต้องทำให้เหมือนกัน
        // ในที่นี้ใช้ u, v ตามที่รับมาเลยเพราะโจทย์ระบุจุดยอดเป็น 1, 2, ..., N
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

void bfs(int s) {
    queue<int> Q;
    Q.push(s);
    seen[s] = true;
    
    while(!Q.empty()) {
        int u = Q.front();
        Q.pop();
        
        for(int v : adj[u]) {
            if(!seen[v]) {
                seen[v] = true;
                Q.push(v);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    read_input();
    
    int components = 0;
    // วนลูปตรวจสอบทุกจุดยอดตั้งแต่ 1 ถึง N
    for(int i = 1; i <= n; i++) {
        if(!seen[i]) {
            // ถ้าเจอจุดที่ยังไม่เคยไป แสดงว่าเป็นกลุ่มใหม่
            components++;
            bfs(i); // ท่องไปให้ทั่วกลุ่มนี้
        }
    }
    
    // พิมพ์จำนวนกลุ่มที่นับได้
    cout << components << endl;
    
    return 0;
}
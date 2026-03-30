#include <iostream>
#include <vector>
using namespace std;



int main() {
    int N, M;       // N = จำนวน node, M = จำนวน edge
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        int Ci;
        cin >> Ci;
    }
    vector<vector<int>> adj(N + 1);   // index 1-based

    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);          // undirected: ใส่ทั้งสองทาง
        adj[y].push_back(x);
    }

    // ถ้าเลือก node i ใดๆแล้วให้เก็บ node นั้นเข้า set 1 และ node ที่อยู่ติดกับ node i ต้องไม่อยู่ใน set 1 ให้สร้าง set 2 ขึ้นมาเก็บ node ที่อยู่ติดกับ node i และตรวจสอบว่า node ที่อยู่ใน set 2 มี node ที่อยู่ใน set 1 หรือไม่ ถ้ามีให้ตอบ no ถ้าไม่มีให้ตอบ yes แต้ถ้า node N ที่ input เข้ามาในตอนแรกมีค่าซ้ำกันให้หา node ที่มีค่า Ci ซ้ำกันและตรวจสอบว่า node ที่มีค่า Ci ซ้ำกันอยู่ติดกับ node ไหนบ้าง ถ้า node ที่มีค่า Ci ซ้ำกันอยู่ติดกับ node ที่มีค่า Ci ซ้ำกันอีกตัวหนึ่งให้ตอบ no ถ้าไม่มีให้ตอบ yes
    for (int i = 1; i <= N; i++) {
        for (int j : adj[i]) {
            if (i < j) { // ตรวจสอบเฉพาะคู่ (i, j) ที่ i < j เพื่อหลีกเลี่ยงการตรวจสอบซ้ำ
                // สมมติว่า Ci ของ node i และ node j เป็นค่าเดียวกัน
                // ในกรณีนี้เราจะต้องตรวจสอบว่า node i และ node j อยู่ติดกันหรือไม่
                // ถ้าอยู่ติดกันให้ตอบ no
                // ถ้าไม่อยู่ติดกันให้ตอบ yes
                // ในที่นี้เราจะสมมติว่า Ci ของ node i และ node j เป็นค่าเดียวกันเพื่อทดสอบ logic
                bool same_Ci = true; // สมมติว่า Ci ของ node i และ node j เป็นค่าเดียวกัน
                if (same_Ci) {
                    cout << "no\n";
                    return 0;
                }
            }
        }
    }
    

    cout << "yes\n";
}
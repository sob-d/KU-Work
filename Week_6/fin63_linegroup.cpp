#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const long long INF = 1e18; // กำหนดค่าที่มากเป็นพิเศษ

int main() {
    // เพิ่มความเร็วในการรับข้อมูล
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return 0;

    vector<int> a(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> a[i];
    }

    // dp[i] คือค่าความรำคาญรวมน้อยที่สุดที่จัดการถึงคนที่ i
    vector<long long> dp(N + 1, INF);
    dp[0] = 0; // จุดเริ่มต้น

    for (int i = 2; i <= N; i++) {
        int max_val = -1;
        int min_val = 10001;

        // ลองสร้างกลุ่มขนาด k ตั้งแต่ 2 ถึง 10
        // โดยกลุ่มนี้จะจบที่นักเรียนคนที่ i
        for (int k = 1; k <= 10; k++) {
            int current_idx = i - k + 1;
            if (current_idx < 1) break; // เกินขอบเขตจำนวนนักเรียน

            // อัปเดตค่า max/min ของกลุ่มปัจจุบัน
            max_val = max(max_val, a[current_idx]);
            min_val = min(min_val, a[current_idx]);

            // เงื่อนไข: กลุ่มต้องมีขนาดอย่างน้อย 2 คน
            if (k >= 2) {
                if (dp[i - k] != INF) {
                    long long current_cost = max_val - min_val;
                    dp[i] = min(dp[i], dp[i - k] + current_cost);
                }
            }
        }
    }

    cout << dp[N] << endl;

    return 0;
}
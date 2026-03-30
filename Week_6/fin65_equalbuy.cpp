#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// กำหนดค่า Max Sum ตามโจทย์ (รวมไม่เกิน 300)
const int MAX_SUM = 300;
const int OFFSET = 300; // ใช้ offset เพื่อป้องกัน index ติดลบ

int main() {
    int N;
    if (!(cin >> N)) return 0;

    vector<int> p(N);
    for (int i = 0; i < N; i++) cin >> p[i];

    // dp[diff] เก็บผลรวมราคาสูงสุดของคุณ เมื่อส่วนต่างระหว่างคุณกับเพื่อนคือ diff
    // ให้ -1 แทนที่เป็นไปไม่ได้
    vector<int> dp(2 * MAX_SUM + 1, -1);
    
    // เริ่มต้น: ผลต่าง 0 (ยังไม่ได้ซื้อทั้งคู่) คุณมีมูลค่า 0
    dp[OFFSET] = 0;

    for (int price : p) {
        vector<int> next_dp = dp;
        for (int d = 0; d <= 2 * MAX_SUM; d++) {
            if (dp[d] == -1) continue;

            // ทางเลือกที่ 1: คุณซื้อชิ้นนี้ (ผลต่างเพิ่มขึ้น)
            if (d + price <= 2 * MAX_SUM) {
                next_dp[d + price] = max(next_dp[d + price], dp[d] + price);
            }

            // ทางเลือกที่ 2: เพื่อนซื้อชิ้นนี้ (ผลต่างลดลง)
            if (d - price >= 0) {
                next_dp[d - price] = max(next_dp[d - price], dp[d]);
            }
            
            // ทางเลือกที่ 3: ไม่ซื้อ (next_dp มีค่าเดิมอยู่แล้ว)
        }
        dp = next_dp;
    }

    // คำตอบคือ dp ที่ผลต่างเป็น 0 (OFFSET)
    if (dp[OFFSET] > 0) {
        cout << dp[OFFSET] << endl;
    } else {
        cout << 0 << endl;
    }

    return 0;
}
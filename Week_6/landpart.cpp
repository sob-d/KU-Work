#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    if (!(cin >> N)) return 0;

    vector<int> p(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> p[i];
    }

    // dp[i] เก็บผลรวมมูลค่าสูงสุดของที่ดินส่วนที่ 1 ถึง i
    // เริ่มต้นให้เป็น 0
    vector<long long> dp(N + 1, 0);

    for (int i = 1; i <= N; i++) {
        // ลองแบ่งที่ดินเป็นแปลงสุดท้าย โดยต้องมีอย่างน้อย 5 ส่วน
        // ดังนั้นแปลงสุดท้ายต้องจบที่ i และเริ่มย้อนกลับไปได้ไม่เกินตำแหน่งที่ i-4
        
        int current_max = 0;
        
        // j คือจุดเริ่มต้นของแปลงสุดท้าย
        // แปลงสุดท้ายต้องมีความยาวอย่างน้อย 5 (i-j+1 >= 5)
        for (int j = i; j >= 1; j--) {
            // อัปเดตค่า Max ในช่วง j ถึง i
            current_max = max(current_max, p[j]);
            
            // เช็คว่าแปลงที่เริ่มที่ j จบที่ i มีความยาว >= 5 หรือไม่
            if (i - j + 1 >= 5) {
                // ถ้าเป็นแปลงแรกของที่ดินทั้งหมด (j=1)
                if (j == 1) {
                    dp[i] = max(dp[i], (long long)current_max);
                } 
                // ถ้าไม่ใช่แปลงแรก ต้องบวกกับค่าสูงสุดที่เคยทำได้ก่อนหน้า (dp[j-1])
                // และต้องมั่นใจว่าก่อนหน้า (j-1) เคยมีการแบ่งที่ถูกต้อง (dp[j-1] > 0)
                else if (dp[j - 1] > 0) {
                    dp[i] = max(dp[i], dp[j - 1] + current_max);
                }
            }
        }
    }

    cout << dp[N] << endl;

    return 0;
}
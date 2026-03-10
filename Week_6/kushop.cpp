#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // เพิ่มความเร็วในการ Input/Output
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return 0;

    if (N == 0) {
        cout << 0 << endl;
        return 0;
    }

    vector<long long> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    // กรณีมีร้านเดียว
    if (N == 1) {
        cout << v[0] << endl;
        return 0;
    }

    // ใช้ตัวแปรเก็บค่าเพื่อประหยัด Memory (Space Optimization)
    // prev2 คือ dp[i-2], prev1 คือ dp[i-1]
    long long prev2 = 0;
    long long prev1 = v[0];
    long long current = 0;

    for (int i = 1; i < N; i++) {
        // เลือกระหว่าง (ไม่เอาตัวปัจจุบัน) กับ (เอาตัวปัจจุบัน + ผลรวมก่อนหน้า 2 จุด)
        current = max(prev1, v[i] + prev2);
        
        // เลื่อนตำแหน่งสำหรับรอบถัดไป
        prev2 = prev1;
        prev1 = current;
    }

    cout << prev1 << endl;

    return 0;
}
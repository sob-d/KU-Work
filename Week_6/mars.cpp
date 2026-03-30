#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;

// ฟังก์ชันหาระยะการหมุนที่สั้นที่สุดบนวงล้อ 26 ตัวอักษร
int get_dist(int current, int target) {
    int diff = abs(current - target);
    return min(diff, 26 - diff);
}

void solve() {
    string s;
    cin >> s;
    int n = s.length();

    // dp[L][R] เก็บค่าใช้จ่ายน้อยที่สุดที่ล้อซ้ายอยู่ที่ L และล้อขวาอยู่ที่ R
    vector<vector<int>> dp(26, vector<int>(26, INF));

    // เริ่มต้นทั้งสองล้ออยู่ที่ 'A' (แทนด้วยเลข 0)
    dp[0][0] = 0;

    for (char c : s) {
        int target = c - 'A';
        vector<vector<int>> next_dp(26, vector<int>(26, INF));

        for (int l = 0; l < 26; l++) {
            for (int r = 0; r < 26; r++) {
                if (dp[l][r] == INF) continue;

                // ทางเลือก 1: ใช้ล้อซ้ายหมุนไปที่ target
                next_dp[target][r] = min(next_dp[target][r], dp[l][r] + get_dist(l, target));

                // ทางเลือก 2: ใช้ล้อขวาหมุนไปที่ target
                next_dp[l][target] = min(next_dp[l][target], dp[l][r] + get_dist(r, target));
            }
        }
        dp = next_dp;
    }

    // หาค่าที่น้อยที่สุดในตารางสุดท้าย
    int ans = INF;
    for (int l = 0; l < 26; l++) {
        for (int r = 0; r < 26; r++) {
            ans = min(ans, dp[l][r]);
        }
    }
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
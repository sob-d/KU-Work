#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const long long INF = 1e18;

int main() {
    int H, L;
    long long B;
    if (!(cin >> H >> L >> B)) return 0;

    vector<vector<int>> A(H, vector<int>(L));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < L; j++) {
            cin >> A[i][j];
        }
    }

    vector<vector<long long>> dp(H, vector<long long>(L, INF));

    for (int i = 0; i < H; i++) {
        dp[i][0] = A[i][0];
    }

    for (int j = 1; j < L; j++) {
        for (int i = 0; i < H; i++) {
            dp[i][j] = min(dp[i][j], dp[i][j - 1] + A[i][j]);

            if (i - 1 >= 0) {
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + A[i][j] + B);
            }
            
            if (i + 1 < H) {
                dp[i][j] = min(dp[i][j], dp[i + 1][j - 1] + A[i][j] + B);
            }
        }
    }

    long long ans = INF;
    for (int i = 0; i < H; i++) {
        ans = min(ans, dp[i][L - 1]);
    }

    cout << ans << endl;

    return 0;
}
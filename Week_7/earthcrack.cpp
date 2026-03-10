#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

void solve() {
    int M, N;
    if (!(cin >> M >> N)) return;

    vector<vector<int>> energy(M, vector<int>(N));
    vector<vector<ll>> dp(M, vector<ll>(N));

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> energy[i][j];
        }
    }

    for (int j = 0; j < N; j++) {
        dp[0][j] = energy[0][j];
    }

    for (int i = 1; i < M; i++) {
        for (int j = 0; j < N; j++) {
            ll prev_min = dp[i-1][j];

            if (j > 0) {
                prev_min = min(prev_min, dp[i-1][j-1]);
            }

            if (j < N - 1) {
                prev_min = min(prev_min, dp[i-1][j+1]);
            }

            dp[i][j] = energy[i][j] + prev_min;
        }
    }

    ll result = dp[M-1][0];
    for (int j = 1; j < N; j++) {
        if (dp[M-1][j] < result) {
            result = dp[M-1][j];
        }
    }

    cout << result << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
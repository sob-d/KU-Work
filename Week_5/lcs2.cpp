#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string S, T;
    if (!(cin >> S >> T)) return 0;

    int n = S.length();
    int m = T.length();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (S[i - 1] == T[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    string res = "";
    int i = n, j = m;
    while (i > 0 && j > 0) {
        if (S[i - 1] == T[j - 1]) {
            res += S[i - 1];
            i--;
            j--;
        } else if (dp[i - 1][j] >= dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    reverse(res.begin(), res.end());

    cout << dp[n][m] << endl;
    cout << res << endl;

    return 0;
}
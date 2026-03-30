#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string X, Y;
    if (!(cin >> X >> Y)) return 0;

    int n = X.length();
    int m = Y.length();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1));

    for (int i = 0; i <= n; ++i) dp[i][0] = i;
    for (int j = 0; j <= m; ++j) dp[0][j] = j;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            int cost = (X[i - 1] == Y[j - 1]) ? 0 : 1;
            
            dp[i][j] = min({
                dp[i - 1][j - 1] + cost,
                dp[i - 1][j] + 1,
                dp[i][j - 1] + 1
            });
        }
    }

    cout << dp[n][m] << endl;

    return 0;
}
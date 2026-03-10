#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool canPair(char a, char b) {
    if ((a == 'A' && b == 'U') || (a == 'U' && b == 'A')) return true;
    if ((a == 'C' && b == 'G') || (a == 'G' && b == 'C')) return true;
    return false;
}

int main() {
    string B;
    if (!(cin >> B)) return 0;
    int N = B.length();

    vector<vector<int>> dp(N, vector<int>(N, 0));

    for (int len = 6; len <= N; len++) {
        for (int i = 0; i <= N - len; i++) {
            int j = i + len - 1;

            dp[i][j] = dp[i][j-1];

            for (int k = i; k <= j - 5; k++) {
                if (canPair(B[k], B[j])) {
                    int before = (k > i) ? dp[i][k-1] : 0;
                    int inside = dp[k+1][j-1];
                    dp[i][j] = max(dp[i][j], 1 + before + inside);
                }
            }
        }
    }

    cout << dp[0][N-1] << endl;

    return 0;
}
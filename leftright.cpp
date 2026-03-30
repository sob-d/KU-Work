#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const long long INF = 1e18;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int M, N;
    if (!(cin >> M >> N)) return 0;

    vector<vector<int>> grid(M, vector<int>(N));
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
        /*if input = 5 6
1 2 -5 10 1 1
-4 4 -1 5 -2 -3
-1 2 1 3 4 -10
-3 -5 -2 -10 3 1
2 1 1 1 4 2
output = 37
*/
        }
    }
    
    vector<vector<long long>> dp(M, vector<long long>(N, -INF));

    for (int j = 0; j < N; j++) {
        dp[0][j] = grid[0][j];
    }

    // odd row can only move right many times even row can only move left many times do recursion on each row to find the path that earn the most point(try go to minus number) but not up (remember rule of odd and even row) 
    
        for (int i = 1; i < M; i++) {
            // if in odd row can move right many times or down, if in even row can move left many times or down
            if (i % 2 == 1) {
                for (int j = 0; j < N; j++) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j] + grid[i][j]);
                    if (j > 0) {
                        dp[i][j] = max(dp[i][j], dp[i][j - 1] + grid[i][j]);
                    }
                }
            } else {
                for (int j = N - 1; j >= 0; j--) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j] + grid[i][j]);
                    if (j < N - 1) {
                        dp[i][j] = max(dp[i][j], dp[i][j + 1] + grid[i][j]);
                    }
                }
            }
        }


    long long ans = -INF;
    for (int j = 0; j < N; j++) {
        ans = max(ans, dp[M - 1][j]);
    }
    
    cout << ans << "\n";
}
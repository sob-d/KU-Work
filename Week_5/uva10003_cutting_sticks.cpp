#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;

int main() {
    int L;
    while (cin >> L && L != 0) {
        int n;
        cin >> n;
        
        vector<int> cuts;
        cuts.push_back(0);
        for (int i = 0; i < n; ++i) {
            int c;
            cin >> c;
            cuts.push_back(c);
        }
        cuts.push_back(L);

        int m = cuts.size();
        vector<vector<int>> dp(m, vector<int>(m, 0));

        for (int len = 2; len < m; ++len) {
            for (int i = 0; i + len < m; ++i) {
                int j = i + len;
                dp[i][j] = INF;
                
                for (int k = i + 1; k < j; ++k) {
                    int cost = dp[i][k] + dp[k][j] + (cuts[j] - cuts[i]);
                    dp[i][j] = min(dp[i][j], cost);
                }
            }
        }

        cout << "The minimum cutting is " << dp[0][m - 1] << "." << endl;
    }
    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, K;
    if (!(cin >> N >> K)) return 0;
    int max_jump = K + 1;
    vector<int> dp(N + 1, 0);

    dp[0] = 1;

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= max_jump; ++j) {
            if (i - j >= 0) {
                dp[i] = (dp[i] + dp[i - j]) % 9377;
            }
        }
    }

    cout << dp[N] << endl;

    return 0;
}
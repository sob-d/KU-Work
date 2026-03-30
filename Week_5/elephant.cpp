#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return 0;

    vector<long long> A(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
    }

    vector<long long> dp(N + 1, 0);

    for (int i = 1; i <= N; ++i) {
        dp[i] = dp[i - 1];

        if (i >= 3) {
            dp[i] = max(dp[i], A[i] + dp[i - 3]);
        }
    }

    cout << dp[N] << endl;

    return 0;
}
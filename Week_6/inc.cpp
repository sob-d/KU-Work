#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<int> S(N), dp(N, 1), parent(N, -1);

    for (int i = 0; i < N; i++) cin >> S[i];

    int max_len = 0, last_idx = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (S[j] < S[i] && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
                parent[i] = j;
            }
        }
        if (dp[i] > max_len) {
            max_len = dp[i];
            last_idx = i;
        }
    }

    // แสดงความยาว
    cout << max_len << endl;

    // ดึงลำดับออกมาโดยใช้ parent
    vector<int> result;
    int curr = last_idx;
    while (curr != -1) {
        result.push_back(S[curr]);
        curr = parent[curr];
    }
    reverse(result.begin(), result.end());

    // แสดงตัวเลขในลำดับ
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << (i == result.size() - 1 ? "" : " ");
    }
    cout << endl;

    return 0;
}
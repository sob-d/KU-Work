#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;

    vector<long long> prefix_sum(N + 1, 0);
    for (int i = 1; i <= N; ++i) {
        int cost;
        cin >> cost;
        prefix_sum[i] = prefix_sum[i - 1] + cost;
    }

    for (int j = 0; j < K; ++j) {
        long long money;
        cin >> money;

        auto it = upper_bound(prefix_sum.begin() + 1, prefix_sum.end(), money);
        
        cout << distance(prefix_sum.begin() + 1, it) << "\n";
    }

    return 0;
}

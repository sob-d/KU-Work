#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long countPairsNotExceed(const vector<long long>& prices, long long target) {
    long long count = 0;
    int left = 0;
    int right = prices.size() - 1;

    while (left < right) {
        if (prices[left] + prices[right] <= target) {
            count += (right - left);
            left++;
        } else {
            right--;
        }
    }
    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    long long A, B;
    if (!(cin >> N >> A >> B)) return 0;

    vector<long long> prices(N);
    for (int i = 0; i < N; i++) {
        cin >> prices[i];
    }

    sort(prices.begin(), prices.end());

    long long ans = countPairsNotExceed(prices, B) - countPairsNotExceed(prices, A - 1);

    cout << ans << endl;

    return 0;
}
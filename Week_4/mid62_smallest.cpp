#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, Q;
    cin >> N >> Q;

    vector<int> h(N + 1);
    vector<int> pref_min(N + 1);
    
    int current_min = 2e9;
    for (int i = 1; i <= N; ++i) {
        cin >> h[i];
        if (h[i] < current_min) {
            current_min = h[i];
        }
        pref_min[i] = current_min;
    }

    while (Q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int j;
            cin >> j;
            cout << pref_min[j] << "\n";
        } else {
            int k;
            cin >> k;
            int low = 1, high = N, ans = 0;
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (pref_min[mid] >= k) {
                    ans = mid;
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
            cout << ans << "\n";
        }
    }

    return 0;
}
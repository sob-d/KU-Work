#include <iostream>
#include <set>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    if (!(cin >> N >> M)) return 0;

    set<int> s;
    for (int i = 0; i < N; ++i) {
        int x;
        cin >> x;
        s.insert(x);
    }

    for (int j = 0; j < M; ++j) {
        int y;
        cin >> y;

        auto it = s.lower_bound(y);

        if (it == s.begin()) {
            cout << *it << "\n";
        } else if (it == s.end()) {
            cout << *(--it) << "\n";
        } else {
            int val_high = *it;
            int val_low = *(--it);

            if (abs(val_high - y) < abs(val_low - y)) {
                cout << val_high << "\n";
            } else {
                cout << val_low << "\n";
            }
        }
    }

    return 0;
}
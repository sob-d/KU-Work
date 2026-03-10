#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    if (!(cin >> N >> M)) return 0;

    multiset<int> ships;
    for (int i = 0; i < N; ++i) {
        int capacity;
        cin >> capacity;
        ships.insert(capacity);
    }

    int weeks_count = 0;
    bool failed = false;

    for (int j = 0; j < M; ++j) {
        int demand;
        cin >> demand;

        if (!failed) {
            auto it = ships.lower_bound(demand);

            if (it != ships.end()) {
                weeks_count++;
                ships.erase(it);
            } else {
                failed = true;
            }
        }
    }

    cout << weeks_count << endl;

    return 0;
}
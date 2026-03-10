#include <iostream>
#include <queue>
#include <unordered_set>

using namespace std;

int main() {
    int N, M;
    if (!(cin >> N >> M)) return 0;

    unordered_set<int> in_cache;
    queue<int> order;
    int misses = 0;

    for (int i = 0; i < M; ++i) {
        int page_id;
        cin >> page_id;

        if (in_cache.find(page_id) == in_cache.end()) {
            misses++;

            if (in_cache.size() == N) {
                int oldest = order.front();
                order.pop();
                in_cache.erase(oldest);
            }

            in_cache.insert(page_id);
            order.push(page_id);
        }
    }

    cout << misses << endl;

    return 0;
}
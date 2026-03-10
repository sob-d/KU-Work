#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct House {
    long long s, t;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    long long L;
    if (!(cin >> N >> L)) return 0;

    vector<House> houses(N);
    for (int i = 0; i < N; ++i) {
        cin >> houses[i].s >> houses[i].t;
    }

    int fence_count = 0;
    long long current_fence_end = -1;

    for (int i = 0; i < N; ++i) {
        if (houses[i].t > current_fence_end) {
            fence_count++;
            current_fence_end = houses[i].s + L;
        }
    }

    cout << fence_count << endl;

    return 0;
}
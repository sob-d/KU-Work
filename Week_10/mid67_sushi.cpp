#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Interval {
    long long l, r;
};

bool compareIntervals(Interval a, Interval b) {
    if (a.r != b.r) return a.r < b.r;
    return a.l < b.l;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    long long L;
    if (!(cin >> N >> L)) return 0;

    vector<Interval> intervals;
    for (int i = 0; i < N; ++i) {
        long long a, b;
        cin >> a >> b;

        if (b > L) {
            cout << -1 << endl;
            return 0;
        }

        long long range = L - b;
        intervals.push_back({a - range, a + range});
    }

    sort(intervals.begin(), intervals.end(), compareIntervals);

    int count = 0;
    long long last_pos = -2e18;

    for (int i = 0; i < N; ++i) {
        if (intervals[i].l > last_pos) {
            count++;
            last_pos = intervals[i].r;
        }
    }

    cout << count << endl;

    return 0;
}
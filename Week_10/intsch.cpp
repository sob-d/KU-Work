#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Interval {
    int start, end;
};

bool compareIntervals(const Interval& a, const Interval& b) {
    return a.end < b.end;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return 0;

    vector<Interval> tasks(N);
    for (int i = 0; i < N; ++i) {
        cin >> tasks[i].start >> tasks[i].end;
    }

    sort(tasks.begin(), tasks.end(), compareIntervals);

    int count = 0;
    int current_end_time = -1;

    for (int i = 0; i < N; ++i) {
        if (tasks[i].start >= current_end_time) {
            count++;
            current_end_time = tasks[i].end;
        }
    }

    cout << count << endl;

    return 0;
}
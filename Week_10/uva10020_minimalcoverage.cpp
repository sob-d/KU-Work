#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Segment {
    int l, r;
};

bool compareSegments(const Segment& a, const Segment& b) {
    return a.l < b.l;
}

void solve() {
    int M;
    cin >> M;
    
    vector<Segment> segments;
    int l, r;
    while (cin >> l >> r && (l != 0 || r != 0)) {
        segments.push_back({l, r});
    }

    sort(segments.begin(), segments.end(), compareSegments);

    vector<Segment> result;
    int current_end = 0;
    int i = 0;
    bool possible = false;

    while (current_end < M) {
        int best_r = current_end;
        int chosen_idx = -1;

        while (i < segments.size() && segments[i].l <= current_end) {
            if (segments[i].r > best_r) {
                best_r = segments[i].r;
                chosen_idx = i;
            }
            i++;
        }

        if (chosen_idx == -1) break;

        result.push_back(segments[chosen_idx]);
        current_end = best_r;
        
        if (current_end >= M) {
            possible = true;
            break;
        }
    }

    if (possible) {
        cout << result.size() << "\n";
        for (const auto& s : result) {
            cout << s.l << " " << s.r << "\n";
        }
    } else {
        cout << "0\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test_cases;
    cin >> test_cases;
    while (test_cases--) {
        solve();
        if (test_cases > 0) cout << "\n";
    }
    return 0;
}
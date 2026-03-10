#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int W, H, M, N;
    if (!(cin >> W >> H >> M >> N)) return 0;

    vector<int> x_cuts = {0, W};
    for (int i = 0; i < M; i++) {
        int val; cin >> val;
        x_cuts.push_back(val);
    }
    sort(x_cuts.begin(), x_cuts.end());

    vector<int> y_cuts = {0, H};
    for (int i = 0; i < N; i++) {
        int val; cin >> val;
        y_cuts.push_back(val);
    }
    sort(y_cuts.begin(), y_cuts.end());

    vector<int> widths;
    for (size_t i = 1; i < x_cuts.size(); i++) {
        widths.push_back(x_cuts[i] - x_cuts[i-1]);
    }

    vector<int> heights;
    for (size_t i = 1; i < y_cuts.size(); i++) {
        heights.push_back(y_cuts[i] - y_cuts[i-1]);
    }

    vector<long long> areas;
    for (int w : widths) {
        for (int h : heights) {
            areas.push_back((long long)w * h);
        }
    }

    sort(areas.begin(), areas.end(), greater<long long>());

    cout << areas[0] << " " << areas[1] << endl;

    return 0;
}
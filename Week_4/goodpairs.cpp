#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    long long S, T;
    if (!(cin >> N >> S >> T)) return 0;

    vector<long long> p(N);
    for (int i = 0; i < N; ++i) {
        cin >> p[i];
    }

    long long count = 0;
    int left = 0;

    for (int j = 1; j < N; ++j) {
        long long min_pi = max(S - p[j], p[j] - T);

        
        
        auto it = lower_bound(p.begin(), p.begin() + j, min_pi);
        int i_start = distance(p.begin(), it);

        
        if (i_start < j) {
            count += (j - i_start);
        }
    }

    cout << count << endl;

    return 0;
}
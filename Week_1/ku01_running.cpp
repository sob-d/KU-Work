#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    long long K;
    if (!(cin >> N >> K)) return 0;

    vector<long long> S(N);
    long long S_min = 2000000000;

    for (int i = 0; i < N; i++) {
        cin >> S[i];
        if (S[i] < S_min) {
            S_min = S[i];
        }
    }

    long long winner_total_time = K * S_min;

    int survivor_count = 0;
    for (int i = 0; i < N; i++) {
        if ((K - 1) * S[i] < winner_total_time) {
            survivor_count++;
        }
    }

    cout << survivor_count << "\n";

    return 0;
}
#include <iostream>

using namespace std;

int main() {
    long long L, N;
    cin >> L >> N;

    long long current_total = 0;
    long long k = 0;

    while (current_total < N) {
        k++;
        current_total += (k * L);
    }

    long long prev_total = (k - 1) * k / 2 * L;
    long long remaining = N - prev_total;

    long long ans = (remaining + L - 1) / L;

    cout << ans << endl;

    return 0;
}
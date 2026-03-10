#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    long long N;
    if (!(cin >> N)) return 0;

    if (N == 1) {
        cout << 0 << endl;
        return 0;
    }

    long long r = ceil(sqrt(N));

    long long first_in_row = (r - 1) * (r - 1) + 1;
    long long pos = N - first_in_row + 1;

    long long dist_from_center = abs(pos - r);

    long long ans = 2 * (r - 1) - dist_from_center;

    cout << ans << endl;

    return 0;
}
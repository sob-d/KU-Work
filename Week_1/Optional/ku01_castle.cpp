#include <iostream>
#include <cmath>

using namespace std;

int main() {
    long long N;
    cin >> N;

    if (N == 1) {
        cout << 0 << endl;
        return 0;
    }
    long long r = ceil(sqrt(N));
    long long center = r * r - r + 1;
    long long dist = abs(N - center);
    long long ans = (r - 1) + dist;

    cout << ans << endl;

    return 0;
}
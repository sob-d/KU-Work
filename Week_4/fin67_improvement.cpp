#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;
    if (!(cin >> N)) return 0;

    vector<int> x(N);
    for (int i = 0; i < N; ++i) {
        cin >> x[i];
    }

    int countA = 0;
    int countB = 0;
    int max_future = -1;

    for (int i = N - 1; i >= 0; --i) {
        if (max_future != -1) {
            if (max_future >= 3 * x[i]) {
                countA++;
            } else if (max_future >= 2 * x[i]) {
                countB++;
            }
        }
        if (x[i] > max_future) {
            max_future = x[i];
        }
    }

    cout << countA << " " << countB << endl;

    return 0;
}
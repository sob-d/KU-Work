#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return 0;

    if (N == 1) {
        int h;
        cin >> h;
        cout << 1 << endl;
        return 0;
    }

    vector<int> H(N);
    for (int i = 0; i < N; i++) {
        cin >> H[i];
    }

    int count = 0;
    for (int i = 0; i < N; i++) {
        if (i == 0) {
            if (H[i] > H[i+1]) count++;
        }
        else if (i == N - 1) {
            if (H[i] > H[i-1]) count++;
        }
        else {
            if (H[i] > H[i-1] && H[i] > H[i+1]) count++;
        }
    }

    cout << count << endl;

    return 0;
}
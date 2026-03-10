#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, T;
    cin >> N >> T;

    vector<long long> input(N + 1);
    for (int i = 1; i <= N; i++) cin >> input[i];

    vector<int> X(N + 1);
    vector<long long> Y(N + 1);

    if (T == 1) {
        for (int i = 1; i <= N; i++) {
            long long prev_val = (i == 1) ? N : input[i-1];
            if (input[i] > prev_val) X[i] = 1;
            else X[i] = 0;
        }
    } else {
        Y[1] = input[1];
        X[1] = (Y[1] == N + 1) ? 1 : 0;
        
        for (int i = 2; i <= N; i++) {
            long long Zi = input[i];
            if (Zi == 2 * Y[i-1] - 1) {
                X[i] = 0;
                Y[i] = Y[i-1] - 1;
            } else {
                X[i] = 1;
                Y[i] = Y[i-1] + 1;
            }
        }
    }

    for (int i = 1; i <= N; i++) cout << X[i] << "\n";

    return 0;
}
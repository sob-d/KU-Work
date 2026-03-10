#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void solve() {
    int N;
    while (cin >> N && N != 0) {
        while (true) {
            vector<int> target(N);
            cin >> target[0];
            if (target[0] == 0) break;
            
            for (int i = 1; i < N; i++) cin >> target[i];

            stack<int> station;
            int current_train = 1;
            bool possible = true;
            int target_idx = 0;

            while (target_idx < N) {
                if (!station.empty() && station.top() == target[target_idx]) {
                    station.pop();
                    target_idx++;
                }
                else if (current_train <= N) {
                    station.push(current_train);
                    current_train++;
                } 
                else {
                    possible = false;
                    break;
                }
            }

            if (possible) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
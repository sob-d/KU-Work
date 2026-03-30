#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> north(N);
    vector<int> south(N);

    for (int i = 0; i < N; i++)
        cin >> north[i];

    for (int i = 0; i < N; i++)
        cin >> south[i];

    // -----------------------
    // bank -> position in south
    // -----------------------
    vector<int> pos(N + 1);

    for (int i = 0; i < N; i++)
        pos[south[i]] = i;

    // -----------------------
    // convert north to index sequence
    // -----------------------
    vector<int> seq(N);

    for (int i = 0; i < N; i++)
        seq[i] = pos[north[i]];

    // -----------------------
    // LIS (non-crossing bridges)
    // -----------------------
    vector<int> lis;

    for (int x : seq) {
        auto it = lower_bound(lis.begin(), lis.end(), x);

        if (it == lis.end())
            lis.push_back(x);
        else
            *it = x;
    }

    cout << lis.size();
}
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int P1, P2, P3;
    if (!(cin >> P1 >> P2 >> P3)) return 0;

    int N;
    cin >> N;

    long long count1 = 0, count2 = 0, count3 = 0;

    for (int i = 0; i < N; i++) {
        int type;
        cin >> type;
        if (type == 1) count1++;
        else if (type == 2) count2++;
        else if (type == 3) count3++;
    }

    long long cost1 = count1 * P1;
    long long cost2 = count2 * P2;
    long long cost3 = count3 * P3;

    long long min_cost = min({cost1, cost2, cost3});

    cout << min_cost << endl;

    return 0;
}
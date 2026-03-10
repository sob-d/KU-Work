#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main() {
    int n[7], caseNum = 1;
    while (true) {
        int totalSum = 0;
        bool allZero = true;
        for (int i = 1; i <= 6; i++) {
            cin >> n[i];
            if (n[i] != 0) allZero = false;
            totalSum += n[i] * i;
        }

        if (allZero) break;

        cout << "Collection #" << caseNum++ << ":" << endl;

        if (totalSum % 2 != 0) {
            cout << "Can't be divided." << endl << endl;
            continue;
        }

        int target = totalSum / 2;
        vector<bool> dp(target + 1, false);
        dp[0] = true;

        for (int i = 1; i <= 6; i++) {
            int num = n[i];
            for (int k = 1; num > 0; k <<= 1) {
                int use = min(k, num);
                int val = use * i;
                for (int v = target; v >= val; v--) {
                    if (dp[v - val]) dp[v] = true;
                }
                num -= use;
            }
        }

        if (dp[target]) {
            cout << "Can be divided." << endl << endl;
        } else {
            cout << "Can't be divided." << endl << endl;
        }
    }
    return 0;
}
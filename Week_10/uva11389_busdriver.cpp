#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, d, r;
    while (cin >> n >> d >> r && (n != 0 || d != 0 || r != 0)) {
        vector<int> morning(n);
        vector<int> evening(n);

        for (int i = 0; i < n; i++) cin >> morning[i];
        for (int i = 0; i < n; i++) cin >> evening[i];

        sort(morning.begin(), morning.end());
        sort(evening.begin(), evening.end(), greater<int>());

        long long total_overtime_pay = 0;
        for (int i = 0; i < n; i++) {
            int total_length = morning[i] + evening[i];
            if (total_length > d) {
                total_overtime_pay += (long long)(total_length - d) * r;
            }
        }

        cout << total_overtime_pay << "\n";
    }

    return 0;
}
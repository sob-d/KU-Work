#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Contract {
    long long c, p, w;
};

int main() {
    int K, N;
    cin >> K >> N;

    vector<Contract> contracts(K);
    for (int i = 0; i < K; ++i) {
        cin >> contracts[i].c >> contracts[i].p >> contracts[i].w;
    }

    vector<int> packages(N);
    for (int i = 0; i < N; ++i) {
        cin >> packages[i];
    }

    long long min_total_cost = -1;

    for (int i = 0; i < K; ++i) {
        long long current_c = contracts[i].c;
        long long current_p = contracts[i].p;
        long long current_w_limit = contracts[i].w;

        int trucks_needed = 1;
        long long current_load = 0;
        bool possible = true;

        for (int j = 0; j < N; ++j) {
            if (packages[j] > current_w_limit) {
                possible = false;
                break;
            }
            if (current_load + packages[j] <= current_w_limit) {
                current_load += packages[j];
            } else {
                trucks_needed++;
                current_load = packages[j];
            }
        }

        if (possible) {
            long long total = current_c + (trucks_needed * current_p);
            if (min_total_cost == -1 || total < min_total_cost) {
                min_total_cost = total;
            }
        }
    }

    cout << min_total_cost << endl;
    return 0;
}
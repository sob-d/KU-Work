#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> sendTo(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> sendTo[i];
    }

    vector<bool> visited(N + 1, false);
    long long max_cycle = 0;

    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            int curr = i;
            long long count = 0;
            

            while (!visited[curr]) {
                visited[curr] = true;
                curr = sendTo[curr];
                count++;
            }
            

            if (count > max_cycle) {
                max_cycle = count;
            }
        }
    }

    cout << max_cycle << "\n";

    return 0;
}
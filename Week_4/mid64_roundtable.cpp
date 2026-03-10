#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return 0;

    vector<int> counter(N, 0);

    for (int i = 1; i <= N; ++i) {
        int food_id;
        cin >> food_id;
        int dist = (food_id - i + N) % N;
        
        counter[dist]++;
    }

    int max_happy_people = 0;
    for (int d = 0; d < N; ++d) {
        if (counter[d] > max_happy_people) {
            max_happy_people = counter[d];
        }
    }

    cout << max_happy_people << endl;

    return 0;
}
#include <iostream>
#include <map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return 0;

    map<int, int> like_counts;
    int current_max_status = 0;
    int max_likes = 0;

    for (int i = 0; i < N; ++i) {
        int status_id;
        cin >> status_id;

        like_counts[status_id]++;
        int current_likes = like_counts[status_id];


        if (current_likes >= max_likes) {
            max_likes = current_likes;
            current_max_status = status_id;
        }

        cout << current_max_status << "\n";
    }

    return 0;
}
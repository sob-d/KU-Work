#include <iostream>
#include <list>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    if (!(cin >> N >> M)) return 0;

    list<int> data;
    for (int i = 0; i < N; ++i) {
        int val;
        cin >> val;
        data.push_back(val);
    }

    auto it = data.begin();

    for (int i = 0; i < M; ++i) {
        int T;
        cin >> T;
        if (T == 1) {
            it = data.begin();
        } 
        else if (T == 2) {
            it++;
            if (it == data.end()) it = data.begin();
        } 
        else if (T == 3) {
            int x;
            cin >> x;
            data.insert(it, x);
        } 
        else if (T == 4) {
            int x;
            cin >> x;
            auto pos_to_insert = next(it); 
            data.insert(pos_to_insert, x);

            auto check_last = it;
            if (++check_last == --data.end()) { 
                auto temp = it;
                if (++temp == --data.end()) {
                    it = data.begin();
                }
            }
        }
    }

    for (int val : data) {
        cout << val << "\n";
    }

    return 0;
}
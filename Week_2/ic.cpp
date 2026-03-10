#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int M;
    if (!(cin >> M)) return 0;

    deque<int> tube;

    for (int i = 0; i < M; i++) {
        string cmd;
        cin >> cmd;

        if (cmd == "li") {
            int X; cin >> X;
            tube.push_front(X);
        } 
        else if (cmd == "ri") {
            int X; cin >> X;
            tube.push_back(X);
        } 
        else if (cmd == "lr") {
            if (!tube.empty()) {
                int temp = tube.front();
                tube.pop_front();
                tube.push_back(temp);
            }
        } 
        else if (cmd == "rr") {
            if (!tube.empty()) {
                int temp = tube.back();
                tube.pop_back();
                tube.push_front(temp);
            }
        }
    }

    for (int val : tube) {
        cout << val << "\n";
    }

    return 0;
}
#include <iostream>
#include <list>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int M;
    if (!(cin >> M)) return 0;

    list<int> myList;

    for (int i = 0; i < M; i++) {
        char command;
        cin >> command;

        if (command == 'I') {
            int X;
            cin >> X;
            myList.push_front(X);
        } 
        else if (command == 'D') {
            int k;
            cin >> k;
            if (k <= (int)myList.size()) {
                auto it = myList.begin();
                for (int j = 1; j < k; j++) {
                    it++;
                }
                myList.erase(it);
            }
        }
    }

    for (int val : myList) {
        cout << val << "\n";
    }

    return 0;
}
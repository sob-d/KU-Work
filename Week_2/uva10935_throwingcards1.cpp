#include <iostream>
#include <queue>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    while (cin >> n && n != 0) {
        queue<int> cards;
        
        for (int i = 1; i <= n; i++) {
            cards.push(i);
        }

        cout << "Discarded cards:";
        
        while (cards.size() > 1) {
            cout << " " << cards.front();
            cards.pop();

            cards.push(cards.front());
            cards.pop();

            if (cards.size() > 1) {
                cout << ",";
            }
        }

        cout << "\nRemaining card: " << cards.front() << "\n";
    }

    return 0;
}
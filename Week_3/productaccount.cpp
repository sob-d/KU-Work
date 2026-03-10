#include <iostream>
#include <map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int M;
    cin >> M;

    map<int, int> inventory;

    for (int i = 0; i < M; ++i) {
        int type;
        cin >> type;

        if (type == 1) {
            int A, B;
            cin >> A >> B;
            inventory[A] += B;
        } 
        else if (type == 2) {
            int A;
            cin >> A;
            cout << inventory[A] << "\n";
        } 
        else if (type == 3) {
            int A, B;
            cin >> A >> B;
            int current_stock = inventory[A];
            int removed = 0;

            if (current_stock >= B) {
                removed = B;
                inventory[A] -= B;
            } else {
                removed = current_stock;
                inventory[A] = 0;
            }
            cout << removed << "\n";
        }
    }

    return 0;
}
#include <iostream>
#include <list>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int M ;
    cin >> M ;

    vector<int> products;
    for (int i = 0; i < M; i++) {
        int T, A, P, Q; 

        cin >> T;
        if (T == 1) {
            cin >> A;
            products.push_back(A);
        } else if (T == 2) {
            cin >> P >> Q;
            //find p in products
            auto it = find(products.begin(), products.end(), P);
            if (it != products.end()) {
                cout << -1 << "\n";
            } else if (it == products.end()) {
                //p plus some number equal q
                int diff = Q - P;
                auto it2 = find(products.begin(), products.end(), diff);
                if (it2 != products.end()) {
                    //cout the index+1 of diff in products
                    cout << distance(products.begin(), it2) + 1 << "\n";
                } else {
                    cout << -1 << "\n";
            }

        }
    }
    }
    return 0;
}


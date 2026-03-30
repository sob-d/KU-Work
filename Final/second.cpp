#include <iostream>
#include <vector>
using namespace std;



int main() {
    int N, M;
    cin >> N >> M;

    vector<int> Ci_values(N + 1);
    for (int i = 0; i < N; i++) {
        int Ci;
        cin >> Ci;
    }
    vector<vector<int>> adj(N + 1);

    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    //collct nodes with the same Ci value
    vector<bool> inSet1(N + 1, false); // เก็บสถานะว่า node อยู่ใน set 1 หรือไม่
    vector<bool> inSet2(N + 1, false); // เก็บสถานะว่า node อยู่ใน set 2 หรือไม่
    
    
    

    cout << "yes\n";
}
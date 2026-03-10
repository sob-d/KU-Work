#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 100005;

int parent[MAX_N];
int sz[MAX_N];

void init(int n) {
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        sz[i] = 1;
    }
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void unite_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (sz[a] < sz[b])
            swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    if (!(cin >> n >> q)) return 0;

    init(n);

    while (q--) {
        char cmd;
        int x, y;
        cin >> cmd >> x >> y;

        if (cmd == 'c') {
            unite_sets(x, y);
        } else if (cmd == 'q') {
            if (find_set(x) == find_set(y)) {
                cout << "yes\n";
            } else {
                cout << "no\n";
            }
        }
    }

    return 0;
}
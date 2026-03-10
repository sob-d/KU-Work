#include <iostream>

using namespace std;

int main() {
    int L;
    long long N;
    if (!(cin >> L >> N)) return 0;

    int layers_removed = 0;
    long long current_N = N;

    for (int i = 1; i <= L; i++) {
        long long oranges_in_layer = (long long)i * i;
        
        if (current_N >= oranges_in_layer) {
            current_N -= oranges_in_layer;
            layers_removed++;
        } else {
            break;
        }
    }

    cout << L - layers_removed << endl;

    return 0;
}
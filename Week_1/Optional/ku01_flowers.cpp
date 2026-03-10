#include <iostream>
#include <cmath>

using namespace std;

int main() {
    long long L, N;
    if (!(cin >> L >> N)) return 0;
    
    long long current_flowers = 0;
    long long k = 0;
    
    while (current_flowers < N) {
        k++;
        current_flowers += (L * k);
    }
    
    
    long long flowers_in_prev_k = L * (k - 1) * k / 2;
    long long remaining = N - flowers_in_prev_k;
    
    long long band = (remaining + L - 1) / L;
    
    cout << band << endl;

    return 0;
}
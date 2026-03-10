#include <iostream>
#include <string>

using namespace std;

string S, T;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> S >> T)) return 0;

    int count = 0;
    int t_idx = 0;
    int s_len = S.length();
    int t_len = T.length();

    while (true) {
        int matched_chars = 0;
        
        while (t_idx < t_len && matched_chars < s_len) {
            if (T[t_idx] == S[matched_chars]) {
                matched_chars++;
            }
            t_idx++;
        }

        if (matched_chars == s_len) {
            count++;
        } else {
            break;
        }
    }

    cout << count << endl;

    return 0;
}
#include <iostream>
#include <string>
#include <list>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string line;
    while (getline(cin, line)) {
        list<char> text;
        auto it = text.begin();

        for (char c : line) {
            if (c == '[') {
                it = text.begin();
            } else if (c == ']') {
                it = text.end();
            } else {
                text.insert(it, c);
            }
        }

        for (char c : text) {
            cout << c;
        }
        cout << "\n";
    }

    return 0;
}
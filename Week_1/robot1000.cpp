#include <iostream>
#include <string>
using namespace std;

int main() {
    int curr_x{0}, curr_y{0};
    string move;
    cin >> move;

    for (char c : move) {
        if (c == 'Z') {
            curr_x = 0;
            curr_y = 0;
        } else if (c == 'N') {
            curr_y++;
        } else if (c == 'E') {
            curr_x++;
        } else if (c == 'W') {
            curr_x--;
        } else if (c == 'S') {
            curr_y--;
        }
    }

    cout << curr_x << " " << curr_y << "\n";
}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K, M;
    cin >> N >> K >> M;
    int count = 0;
    int all_weights = 0;
    int cost = -1;
    vector<int> a(N);
    for (int i = 0; i < N; i++){
        cin >> a[i];
    }
    // sort in vector a
    sort(a.begin(), a.end());

//    for (int i = 0; i < N; i++){
//        cout << a[i];
//    }

    // เลือก K ตัวเลือกที่ดีที่สุด
    for (int i = 0; i < K; i++) {
        count++;
        all_weights += a[i];
    }
//    cout << all_weights << "\n";

    for (int i = 0; i < M; i++) {
        int bj, cj;
        cin >> bj >> cj;

        // ถ้า bj สามารถรับ all_weights ได้และ cj ต้องน้อยที่สุดในที่ input เข้ามา ให้เลือก cj ของ bj ตัวนั้นมาแทนที่ cost
        if (bj >= all_weights) {
            if (cost == -1 || cj < cost) {
                cost = cj;
            }
        }
    }

    cout << cost << "\n";
    return 0;
}
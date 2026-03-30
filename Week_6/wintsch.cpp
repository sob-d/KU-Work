#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Job {
    long long s, t, w, id;
};

int main() {
    int N;
    if (!(cin >> N)) return 0;

    vector<Job> jobs(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> jobs[i].s >> jobs[i].t >> jobs[i].w;
        jobs[i].id = i;
    }

    // 1. หา p[i] โดยใช้ binary search
    vector<int> p(N + 1, 0);
    for (int i = 1; i <= N; i++) {
        int low = 1, high = i - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (jobs[mid].t <= jobs[i].s) {
                p[i] = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    }

    // 2. คำนวณ DP
    vector<long long> dp(N + 1, 0);
    vector<bool> selected(N + 1, false);

    for (int i = 1; i <= N; i++) {
        long long include_weight = jobs[i].w + dp[p[i]];
        if (include_weight > dp[i - 1]) {
            dp[i] = include_weight;
            selected[i] = true; // มาร์คไว้ว่าเลือกงานที่ i แล้วได้ค่าดีกว่า
        } else {
            dp[i] = dp[i - 1];
            selected[i] = false;
        }
    }

    // 3. Backtrack หาว่าเลือกงานไหนบ้าง
    vector<int> result_ids;
    int curr = N;
    while (curr > 0) {
        if (selected[curr]) {
            result_ids.push_back(jobs[curr].id);
            curr = p[curr]; // ถ้าเลือก ให้ข้ามไปดูงานที่จบก่อนหน้านี้
        } else {
            curr--; // ถ้าไม่เลือก ให้ดูงานก่อนหน้าถัดไป
        }
    }

    // 4. แสดงผลลัพธ์
    cout << dp[N] << endl;
    cout << result_ids.size() << endl;
    for (int i = result_ids.size() - 1; i >= 0; i--) {
        cout << result_ids[i] << (i == 0 ? "" : " ");
    }
    cout << endl;

    return 0;
}
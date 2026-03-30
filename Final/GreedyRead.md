# 🟢 Greedy Algorithm — C++ Guide

> **Greedy** คือแนวคิดที่เลือก "ตัวเลือกที่ดีที่สุดในขณะนั้น" (locally optimal) ในแต่ละขั้นตอน โดยหวังว่าผลลัพธ์สุดท้ายจะดีที่สุด (globally optimal)

---

## 📌 โครงสร้างพื้นฐาน (Template)

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    // 1. จัดเรียงก่อนเสมอ (ถ้าจำเป็น)
    sort(a.begin(), a.end());

    long long ans = 0;

    // 2. วนเลือก greedy
    for (int i = 0; i < n; i++) {
        // เลือกตัวเลือกที่ดีที่สุด ณ ขณะนี้
        ans += a[i];
    }

    cout << ans << "\n";
    return 0;
}
```

---

## 🔧 ขั้นตอนการตั้งตัวแปรและเขียนโค้ด

### Step 1 — รับ Input
```cpp
int n;
cin >> n;

vector<int> a(n);          // ใช้ vector เสมอ (ยืดหยุ่นกว่า array)
for (int i = 0; i < n; i++) cin >> a[i];
```

### Step 2 — จัดเรียง (ถ้า greedy ต้องการลำดับ)
```cpp
sort(a.begin(), a.end());              // น้อย → มาก
sort(a.begin(), a.end(), greater<int>()); // มาก → น้อย

// กรณี struct / pair
sort(jobs.begin(), jobs.end(), [](auto& x, auto& y) {
    return x.deadline < y.deadline;    // เรียงตาม deadline
});
```

### Step 3 — ตั้ง Answer & ตัวแปร Tracking
```cpp
long long ans = 0;        // คำตอบสะสม
int count = 0;            // นับจำนวน
int cur = 0;              // ค่าปัจจุบัน (เช่น end ของ interval ล่าสุด)
bool ok = true;           // flag ว่าทำได้ไหม
```

### Step 4 — วน Greedy Loop
```cpp
for (int i = 0; i < n; i++) {
    if (/* เงื่อนไขที่ดีที่สุด */) {
        ans += a[i];
        cur = a[i];
        count++;
    }
}
```

### Step 5 — Output
```cpp
cout << ans << "\n";
```

---

## 📚 ตัวอย่างโจทย์คลาสสิค

---

### 1. Activity Selection (เลือก interval ไม่ทับกัน)

> เลือก interval ได้มากที่สุด โดยไม่ให้เวลาทับกัน

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int,int>> jobs(n);  // {start, end}
    for (auto& [s, e] : jobs) cin >> s >> e;

    // เรียงตาม end time (ยิ่งจบเร็ว ยิ่งดี)
    sort(jobs.begin(), jobs.end(), [](auto& a, auto& b) {
        return a.second < b.second;
    });

    int count = 0;
    int lastEnd = -1;

    for (auto& [s, e] : jobs) {
        if (s >= lastEnd) {     // ไม่ทับกัน
            count++;
            lastEnd = e;
        }
    }

    cout << count << "\n";
    return 0;
}
```

**กุญแจ**: เรียงตาม `end` → เลือกตัวที่ `start >= lastEnd`

---

### 2. Fractional Knapsack (กระเป๋าเป้า)

> ใส่ของให้ได้กำไรสูงสุด (ตัดแบ่งได้)

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, W;
    cin >> n >> W;

    vector<pair<double,double>> items(n);  // {value, weight}
    for (auto& [v, w] : items) cin >> v >> w;

    // เรียงตาม value/weight มาก → น้อย
    sort(items.begin(), items.end(), [](auto& a, auto& b) {
        return (a.first / a.second) > (b.first / b.second);
    });

    double ans = 0;
    double cap = W;

    for (auto& [v, w] : items) {
        if (cap <= 0) break;
        double take = min(cap, w);
        ans += take * (v / w);
        cap -= take;
    }

    cout << fixed << setprecision(2) << ans << "\n";
    return 0;
}
```

**กุญแจ**: เรียงตาม `value/weight` → เอาให้มากที่สุดก่อน

---

### 3. Coin Change (หยอดเหรียญ — greedy version)

> ใช้เหรียญน้อยสุดในการจ่ายเงิน (ใช้ได้เฉพาะบางชุดเหรียญ เช่น 1, 5, 10, 25)

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> coins = {25, 10, 5, 1};  // เรียงมาก → น้อย
    int amount;
    cin >> amount;

    int count = 0;
    for (int c : coins) {
        count += amount / c;
        amount %= c;
    }

    cout << count << "\n";
    return 0;
}
```

> ⚠️ **หมายเหตุ**: Greedy ใช้ได้กับบางชุดเหรียญเท่านั้น หากโจทย์ใช้เหรียญแปลกๆ ต้องใช้ DP

---

### 4. Huffman Coding (บีบอัดข้อมูล)

> สร้าง prefix code ที่สั้นที่สุด

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    priority_queue<int, vector<int>, greater<int>> pq;  // min-heap
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        pq.push(x);
    }

    long long cost = 0;
    while (pq.size() > 1) {
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();
        cost += a + b;
        pq.push(a + b);
    }

    cout << cost << "\n";
    return 0;
}
```

**กุญแจ**: ใช้ `min-heap` → รวม 2 ตัวที่น้อยที่สุดทุกรอบ

---

### 5. Jump Game (กระโดดให้ถึงปลาย)

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int maxReach = 0;

    for (int i = 0; i < n; i++) {
        if (i > maxReach) {
            cout << "NO\n";
            return 0;
        }
        maxReach = max(maxReach, i + a[i]);
    }

    cout << "YES\n";
    return 0;
}
```

---

## 🧠 Checklist ก่อนใช้ Greedy

| คำถาม | ถ้าใช่ |
|---|---|
| ต้องจัดเรียงก่อนไหม? | `sort(...)` |
| ต้องเลือกตัวเล็ก/ใหญ่สุดซ้ำๆ? | ใช้ `priority_queue` |
| มีหลายมิติ (เช่น value + weight)? | เรียงตาม ratio |
| ตัดแบ่งของได้? | Fractional Knapsack |
| ตัดแบ่งไม่ได้? | อาจต้องใช้ DP แทน |

---

## ⚡ Tips

- **Greedy ≠ DP**: Greedy ไม่ย้อนกลับ, DP ลองทุกทาง
- `long long` เสมอถ้าค่าอาจเกิน `2×10⁹`
- ถ้า greedy ให้คำตอบผิด → ลอง DP หรือหา counter-example
- ใช้ `priority_queue<int, vector<int>, greater<int>>` สำหรับ min-heap

---

## 🗂️ สรุป Pattern หลัก

```
Input → Sort/Heap → Greedy Loop → Output
```

| Pattern | เรียงอะไร | โครงสร้าง |
|---|---|---|
| Activity Selection | end time | vector + sort |
| Fractional Knapsack | value/weight | vector + sort |
| Huffman / Merge | frequency | priority_queue (min) |
| Scheduling | deadline | vector + sort |
| Coin Change | ขนาดเหรียญ | array ตายตัว |
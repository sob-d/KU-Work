#include "cave.h"

void exploreCave(int N) {
    int s[N], d[N], conn[N];
    bool found[N]; // เก็บว่าสวิตช์ตัวไหนถูกจับคู่ไปแล้ว

    for (int i = 0; i < N; i++) {
        s[i] = 0;
        conn[i] = -1;
        found[i] = false;
    }

    for (int i = 0; i < N; i++) {
        // --- ขั้นตอนที่ 1: หาว่าประตูบานที่ i ต้องใช้สวิตช์ค่าอะไร (0 หรือ 1) ---
        for (int j = 0; j < N; j++) {
            if (!found[j]) s[j] = 0; // ลองเซตสวิตช์ที่เหลือเป็น 0
        }

        int res = tryCombination(s);
        int target_pos; // ค่าของสวิตช์ที่ทำให้ประตู i เปิด

        // ถ้า res > i หรือ res == -1 แสดงว่าประตู i เปิดแล้ว
        if (res > i || res == -1) target_pos = 0;
        else target_pos = 1;

        // --- ขั้นตอนที่ 2: Binary Search หาสวิตช์ที่คุมประตู i ---
        int left = 0, right = N - 1;
        int switch_idx = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            // เซตสวิตช์ในช่วง [left, mid] ให้เป็นค่าที่เปิดประตู (target_pos)
            // ส่วนนอกช่วงนั้นให้เซตเป็นค่าตรงข้าม (1 - target_pos)
            // (เฉพาะตัวที่ยังไม่โดนจับคู่)
            for (int j = 0; j < N; j++) {
                if (found[j]) continue;
                if (j >= left && j <= mid) s[j] = target_pos;
                else s[j] = 1 - target_pos;
            }

            int res2 = tryCombination(s);
            if (res2 > i || res2 == -1) {
                // ถ้าประตู i เปิด แสดงว่าสวิตช์ที่คุมมันอยู่ในช่วง [left, mid]
                switch_idx = mid;
                right = mid - 1;
            } else {
                // ถ้าประตู i ปิด แสดงว่าสวิตช์ที่คุมมันอยู่ในช่วง [mid + 1, right]
                left = mid + 1;
            }
        }

        // บันทึกผลลัพธ์
        found[switch_idx] = true;
        conn[switch_idx] = i;  // สวิตช์ switch_idx คู่กับประตู i
        s[switch_idx] = target_pos; // Fix สวิตช์ตัวนี้ไว้เพื่อหาประตูถัดไป
    }

    // ส่งคำตอบสุดท้าย
    answer(s, conn);
}
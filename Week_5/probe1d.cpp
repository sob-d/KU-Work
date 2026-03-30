#include "probelib.h"

int main() {
    // 1. เริ่มต้นระบบและรับค่า N
    int n = probe_init();

    int left = 0;
    int right = n - 1;
    int answer = 0;

    // 2. ใช้ Binary Search เพื่อบีบช่วงที่สมบัติจะอยู่
    while (left <= right) {
        if (left == right) {
            answer = left;
            break;
        }

        int mid = left + (right - left) / 2;

        // ตรวจสอบว่าสมบัติอยู่ในช่วง [left, mid] หรือไม่
        if (probe_check(left, mid)) {
            // ถ้าอยู่ช่วงซ้าย ให้ขยับขอบขวามาที่ mid
            answer = mid;
            right = mid;
        } else {
            // ถ้าไม่อยู่ช่วงซ้าย แสดงว่าต้องอยู่ช่วงขวา [mid + 1, right]
            left = mid + 1;
            answer = left;
        }
        
        // กรณีพิเศษ: ถ้าเหลือแค่ 2 ตัว แล้ว left == right 
        // ลูปจะหลุดออกไปตอบเองตามเงื่อนไข
    }

    // 3. ส่งคำตอบสุดท้าย
    probe_answer(answer);

    return 0;
}
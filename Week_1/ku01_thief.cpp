#include <iostream>
using namespace std;

int main() {
  int N, K, T;
  cin >> N >> K >> T;

  int curr_person = 1;
  int curr_check  = 1;

  if (T == 1) {
    cout << 1 << "\n";
    return 0;
  }

  while (true) {
    // ขยับไปอีก K คน (วนรอบ 1..N)
    curr_person = ( (curr_person - 1 + K) % N ) + 1;

    if (curr_person == T) { //เจอขโมยแล้วจ้า
      curr_check++; //เพิ่มคนนับ
      break; //ขโมยได้ของเลย break จบไปซะ
    }

    if (curr_person == 1) {
      break;
    }

    curr_check++; //ถ้ายังไม่เข้าเงื่อนไขบนก็บวกคนเช็คเพิ่มเรื่อยๆ
  }

  cout << curr_check << "\n";
  return 0;
}

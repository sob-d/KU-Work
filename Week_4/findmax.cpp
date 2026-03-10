#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> x;

void read_input()
{
  cin >> n;
  for(int i = 0; i < n; i++) {
    int xx;
    cin >> xx;
    x.push_back(xx);
  }
}

int find_max(vector<int>& x, int n)
{
    // ถ้าเป็น basecase คืน 1 เลยงับ
    if (n == 1) {
        return x[0];
    }

    // หาค่าสูงสุดของ n-1 ตัวแรก
    int max_rest = find_max(x, n - 1);

    // เปรียบเทียบ max ที่ได้กับตัวที่ n-1
    if (x[n - 1] > max_rest) {
        return x[n - 1];
    } else {
        return max_rest;
    }
}

int main()
{
  read_input();
  cout << find_max(x,n) << endl;
}
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

int find_max_index(vector<int>& x, int n)
{
    if (n == 1)
        return 0;

    // หา index ของ max ในช่วง 0 ถึง n-2
    int idx = find_max_index(x, n - 1);

    // เปรียบเทียบ x[n-1] กับ x[idx]
    if (x[n - 1] > x[idx])
        return n - 1;
    else
        return idx;
}

void swap(int& x, int& y)
{
  int t = x;
  x = y;
  y = t;
}

void selection_sort(vector<int>& x, int n)
{
      // base case
    if (n <= 1)
        return;

    // หา index ของค่ามากสุดในช่วง 0..n-1
    int max_index = find_max_index(x, n);

    // สลับให้ค่าสูงสุดไปอยู่ท้าย
    swap(x[max_index], x[n - 1]);

    // sort ช่วง 0..n-2 แบบ recursive
    selection_sort(x, n - 1);
}

int main()
{
  read_input();
  selection_sort(x, n);
  for(int i=0; i<n; i++) {
    cout << x[i] << endl;
  }
}
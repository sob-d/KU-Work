#include <iostream>
using namespace std;

int main() {
  int x,a,b,point = 0;
  cin >> x;
  for (int i = 0; i < x; i++){
    cin >> a >> b;
    int r_squared = a * a + b * b;
    
    if (r_squared <= 4){//กรณี r <= 2
        point += 5;
    } else if (r_squared <= 16){ //กรณี r <= 4
        point += 4;
    } else if (r_squared <= 36){ //กรณี r <= 6
        point += 3;
    } else if (r_squared <= 64){ //กรณี r <= 8
        point += 2;
    } else if (r_squared <= 100){ //กรณี r <= 10
        point += 1;
    } else {
        point += 0; //นอกกระดาน
    }
  }
  cout << point;
  return 0;
}
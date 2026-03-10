#include <iostream>
using namespace std;

int main() {
    int x , y , total = 0;
    cin >> x;
    for (int i = 0; i < x; i++){
        cin >> y;
        
        if (y > 0){
            total += y;
        }
        
    }
    cout << total;
    
    
  return 0;
}
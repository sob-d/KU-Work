#include <iostream>
using namespace std;

int main() {
    int col{0}, plate;
    int arr_plate[301]{0};
    cin >> plate;
    for (int i = 0; i < plate; i++){
        int plate_order;
        cin >> plate_order;
        arr_plate[plate_order] += 1;
    }
    
    for (int i : arr_plate){
        if(i > col){
            col = i;
        }
    }
    cout << col << endl;

    return 0;
}
#include <iostream>
using namespace std;

int main(){
    int floor;
    cout << "몇 층을 쌓겠습니까? (5~100):";
    cin >> floor;
    for(int i = floor; i>0;i--){
        for(int j = 0; j<floor + i-1;j++){
            if(j<floor-i){
                cout << "S";
            }
            else{
                cout << "*";
            }
        }
        cout << endl;
    }
    return 0;
}
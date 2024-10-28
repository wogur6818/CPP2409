#include <iostream>
using namespace std;

int main(){
    float pound, kg;
    cout << "파운드 무게를 입력하세요: ";
    cin >> pound;
    kg = pound / 2.2046;
    cout << "변환된 pound는 " << kg << "kg 입니다." << endl;

    return 0;
}
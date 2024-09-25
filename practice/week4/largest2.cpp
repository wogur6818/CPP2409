#include <iostream>
using namespace std;

int main(){
    int a, b, c, largest;

    cout << "3개의 정수를 입력하시오 : ";
    cin >> a >> b >> c; // 두 개의 숫자가 같을 때 결과가 잘못나올 수 있어 부등호를 크거나 같다로 바꿨습니다.

    if(a>=b){
        if(a>=c){
            cout << "가장 큰 정수는 " << a << endl;
        }
        else {
            cout << "가장 큰 정수는 " << c << endl;
        }
    }
    else{
        if(b >= c){
            cout << "가장 큰 정수는 " << b << endl;
        }
        else{
            cout << "가장 큰 정수는 " << c << endl;
        }
    }
    
    return 0; 
}
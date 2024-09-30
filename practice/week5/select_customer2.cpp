#include <iostream>
#include <string>
using namespace std;

int main(){
    const int maxPeople = 5;
    string names[maxPeople];
    string smax, smin;
    int ages[maxPeople];
    int select, max, min;

    cout << maxPeople << "명의 회원 정보를 입력해주세요." << endl;

    for(int i = 0; i < maxPeople; i++){
        cout << "사람 " << i+1 << "의 이름: ";
        cin >> names[i];
        cout << "사람 " << i+1 << "의 나이: ";
        cin >> ages[i];
    }
    cout << "1. 가장 나이가 많은 사람 출력" << endl;
    cout << "2. 가장 나이가 적은 사람 출력" << endl;
    cout << "3. 종료" << endl;
    cin >> select;

    switch(select){
        case 1:{
            max = ages[0];
            for(int i = 0; i<maxPeople; i++){
                if(max < ages[i]){
                    max = ages[i];
                    smax = names[i];
                }
            }
            for(int i = 0; i < maxPeople; i++){
                if(ages[i] == max){
                    cout << "가장 나이가 많은 사람은 " << ages[i] << "세" << names[i] <<  "입니다." << endl;;
                }
            }
            break;
        }
        case 2:{
            min = ages[0];
            for(int i = 0; i<maxPeople; i++){
                if(min > ages[i]){
                    max = ages[i];
                    smax = names[i];
                }
            }
            for(int i = 0; i < maxPeople; i++){
                if(ages[i] == min){
                    cout << "가장 나이가 적은 사람은 " << ages[i] << "세" << names[i] <<  "입니다." << endl;;
                }
            }
            break;
        }
        case 3:{
            cout << "프로그램을 종료합니다.";
            break;
        }
    }
}
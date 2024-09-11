#include <iostream>

using namespace std;  

int main()
{
    int x, y;
    cout << "현재 가지고 있는 돈 : ";
    cin >> x;
    cout << "캔디의 가격 : ";
    cin >> y;
    cout << "최대로 살 수 있는 캔디 = " << x/y << endl;
    cout << "캔디 구입 후 남은 돈 = " << x%y << endl;

    return 0;
}
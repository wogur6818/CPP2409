#include <iostream>

using namespace std;  

int main()
{
    int x;
    double y;
    cout << "화씨온도 : ";
    cin >> x;
    cout << "섭씨온도 = " << (5.0/9.0)*(x-32) << endl;

    return 0; 
}
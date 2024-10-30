#include <iostream>
using namespace std;

class Rectangle{
public:
    int width, height;
    int CalcArea(){
        return width * height;
    }
};
int main(){
    Rectangle obj, obj2;

    obj.width = 3;
    obj.height = 4;
    int area = obj.CalcArea();
    obj2.width = 10;
    obj2.height = 10;
    int area2 = obj2.CalcArea();
    cout << "사각형 2개의 넓이 : " << area << "," << area2 << endl;
    return 0;
}
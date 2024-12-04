#include <iostream>
using namespace std;

template <typename T1, typename T2>
class Box2 {
    T1 first_data;
    T2 second_data;

public:
    Box2() {    }
    T1 get_fisrt();
    T2 get_second();
    void set_fist(T1 value) {
        first_data = value;
    }
    void set_second(T2 value) {
        second_data = value;
    }
};

template <typename T1, typename T2>
T1 Box2<T1, T2>::get_fisrt() {
    return first_data;
}

template <typename T1, typename T2>
T2 Box2<T1, T2>::get_second() {
    return second_data;
}
int main()
{
    Box2<int, double> b;
    b.set_fist(10);
    b.set_second(3.14);
    cout << "(" << b.get_fisrt() << ", " << b.get_second() << ")" << endl;
    return 0;
}
#include <iostream>
using namespace std;

class RemoteControl {
public:
    virtual void TurnON() = 0;
    virtual void TurnOFF() = 0;
};

class Television : public RemoteControl
{
public:
    void TurnON() override {
        cout << "TV를 켭니다." << endl;
    }
    void TurnOFF() override {
        cout << "TV를 끕니다." << endl;
    }
};

class Refrigerator : public RemoteControl
{
public:
    void TurnON() override {
        cout << "냉장고를 켭니다" << endl;
    }
    void TurnOFF() override {
        cout << "냉장고를 켭니다." << endl;
    }
};

int main() {
    RemoteControl* remoteTV = new Television();
    remoteTV->TurnON();
    remoteTV->TurnOFF();

    RemoteControl* remote_refrigerator = new Refrigerator();
    remote_refrigerator->TurnON();
    remote_refrigerator->TurnOFF();

    delete remoteTV, remote_refrigerator;
    return 0;
}
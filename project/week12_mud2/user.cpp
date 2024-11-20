#include "user.h"
using namespace std;

User::User(string name) : name(name), hp(20), item_Cnt(0) {}

void User::DoAttack() const {
    cout << name << " 공격합니다!" << endl;
}

void User::DecreaseHP(int dec_hp) {
    hp -= dec_hp;
    if (hp < 0) hp = 0;
}

void User::IncreaseHP(int inc_hp) {
    hp += inc_hp;
}

void User::IncreaseItemCount() {
    item_Cnt++;
}

int User::GetHP() const {
    return hp;
}

int User::GetItemCnt() const {
    return item_Cnt;
}

std::string User::GetName() const {
    return name;
}

ostream &operator<<(ostream &os, const User &user) {
    os << "현재 HP는 " << user.GetHP() << "이고, 먹은 아이템은 총 " << user.GetItemCnt() << "개 입니다.";
    return os;
}

Magician::Magician(string name) : User(name) {}

void Magician::DoAttack() const {
    cout << name << " 마법 사용!" << endl;
}

Warrior::Warrior(string name) : User(name) {}

void Warrior::DoAttack() const {
    cout << name << " 베기 사용!" << endl;
}

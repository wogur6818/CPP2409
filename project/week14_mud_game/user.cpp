#include "user.h"
using namespace std;

// User 클래스 정의
User::User(string name) : name(name), hp(20), item_Cnt(0) {}

void User::IncreaseHP(int inc_hp) { hp += inc_hp; }
void User::DecreaseHP(int dec_hp) { hp -= dec_hp; if (hp < 0) hp = 0; }
void User::IncreaseItemCount() { item_Cnt++; }
int User::GetHP() const { return hp; }
int User::GetItemCnt() const { return item_Cnt; }
string User::GetName() const { return name; }

ostream &operator<<(ostream &os, const User &user) {
    os << "현재 HP는 " << user.GetHP() << "이고, 먹은 아이템은 총 " << user.GetItemCnt() << "개 입니다.";
    return os;
}

// Magician 클래스 정의
Magician::Magician(string name) : User(name) {}

string Magician::GetIcon() const {
    return "M";
}

// Warrior 클래스 정의
Warrior::Warrior(string name) : User(name) {}

string Warrior::GetIcon() const {
    return "W";
}

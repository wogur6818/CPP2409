#include "user.h"
using namespace std;


User::User() : hp(20), itemCnt(0) {}

void User::DecreaseHP(int dec_hp){
    hp -= dec_hp;
    if(hp < 0) hp = 0;
}

void User::IncreaseHP(int inc_hp){
    hp += inc_hp;
}

void User::IncreaseItemCount(){
    itemCnt++;
}

int User::GetHP() const {
    return hp;
}

int User::GetItemCnt() const{
    return itemCnt;
}

ostream &operator<<(ostream &os, const User &user) {
    os << "현재 HP는 " << user.GetHP() << "이고, 먹은 아이템은 총 " << user.GetItemCnt() << "개 입니다.";
    return os;
}
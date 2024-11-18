#ifndef USER_H
#define USER_H
#include <iostream>

class User{
private:
    int hp;
    int itemCnt;
public:
    User();
    void IncreaseHP(int inc_hp);
    void DecreaseHP(int dec_hp);
    void IncreaseItemCount();
    int GetHP() const;
    int GetItemCnt() const;
    friend std::ostream& operator<<(std::ostream &os, const User &user);
};

#endif
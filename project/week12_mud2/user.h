#ifndef USER_H
#define USER_H
#include <iostream>
#include <string>

class User {
protected:
    int hp;
    int item_Cnt;
    std::string name;

public:
    User(std::string name = "Default User");
    virtual void DoAttack() const;
    void IncreaseHP(int inc_hp);
    void DecreaseHP(int dec_hp);
    void IncreaseItemCount();
    int GetHP() const;
    int GetItemCnt() const;
    std::string GetName() const; // Getter 함수
    friend std::ostream& operator<<(std::ostream &os, const User &user);
    virtual ~User() {}
};

class Magician : public User {
public:
    Magician(std::string name = "Magician");
    void DoAttack() const override;
};

class Warrior : public User {
public:
    Warrior(std::string name = "Warrior");
    void DoAttack() const override;
};

#endif

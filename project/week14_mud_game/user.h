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
    virtual ~User() {}

    virtual void DoAttack() const = 0;
    virtual std::string GetIcon() const = 0;

    void IncreaseHP(int inc_hp);
    void DecreaseHP(int dec_hp);
    void IncreaseItemCount();
    int GetHP() const;
    int GetItemCnt() const;
    std::string GetName() const;

    friend std::ostream& operator<<(std::ostream &os, const User &user);
};

class Magician : public User {
public:
    Magician(std::string name = "Magician");
    void DoAttack() const override{
        std::cout << name << " 마법 공격!" << std::endl;
    }
    std::string GetIcon() const override;
};

class Warrior : public User {
public:
    Warrior(std::string name = "Warrior");
    void DoAttack() const override{
        std::cout << name << " 베기 사용!" << std::endl;
    }
    std::string GetIcon() const override;
};

#endif

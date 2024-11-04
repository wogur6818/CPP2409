#ifndef USER_H
#define USER_H

class User{
private:
    int hp;
public:
    User();
    void IncreaseHP(int inc_hp);
    void DecreaseHP(int dec_hp);
    int GetHP() const;
};

#endif
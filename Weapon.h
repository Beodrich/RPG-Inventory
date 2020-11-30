#pragma once
#include "Item.h"

class Weapon : public Item
{
public:
    int getDamage() const;
    void setDamage(int damage);
private:
    int damage { 0 };
};
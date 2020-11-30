#include "Weapon.h"

int Weapon::getDamage() const
{
    return damage;
}

void Weapon::setDamage(int damage)
{
    this->damage = damage;
}

#pragma once
#include "Item.h"
#include "Armor.h"
#include "Weapon.h"
#include "Collection.h"
#include <array>
#include <list>
#include "Inventory.h"

using namespace std;

class Character
{
public:
	Character() = default;
	Character(const Character& character) = delete;
	Character& operator = (const Character& character) = delete;

	const Collection<const Item>& getInventory();

	void addItem(const Item& item);
	void dropItem(const Item& item);
	double getTotalWeight() const;

	const Armor* getEquippedArmor(unsigned int slotID) const;
	unsigned int getTotalArmorRating() const;
	void equipArmor(const Armor& armor);
	void unequipArmor(unsigned int slotID);
	const Weapon* getEquippedWeapon() const;
	void equipWeapon(const Weapon& weapon);
	void unequipWeapon();

	void optimizeInventory(double maximumWeight);
	void optimizeEquipment();

	void printInventory() const;
private:
	// add your own private member variables and possibly some private member functions
	Inventory playerInventory;
	 double  totalWeight = 0.0; 
	unsigned int totalArmorRating = 0; 
	//master list of everything 
	list<Armor> armorList;
	list<Weapon> weaponList;
	list<Item> itemList;
	const Armor* equippedArmor[6];
	const Weapon* equippedWeapon;
	bool isWeaponEquiped = false; 
};




#include "Character.h"
#include <list>
#include "Inventory.h"
#include <iostream>
#include<exception>
#include <stdexcept>

/* WORKED ON BY BENJAMIN AND ISSAC. GOT ALOT OF HELP FROM SI TUTROS AND ALECS WITH DEBUGING THE CODE(BECAUSE IT WOULDNT COMPILE). HAD HELP FROM COLE ON HOW TO MAKE THE SORTING FUNCTION FROM INVENTORY .ADD()*/
using namespace std;

void Character::printInventory() const {
	cout << "PRINTING THE INVENTORY" << endl;
	for(auto i: playerInventory.getInventoryList()) {
		try {
			const Armor& armor = dynamic_cast<const Armor&>(*i);
			cout << "Armor Name: "<<armor.getName() << endl;
			cout << "Armor Gold Value: " <<armor.getGoldValue() << endl;
				cout <<"Armor Rating" <<armor.getRating() << endl;
				cout << "Armor Slot Id: "<<armor.getSlotID() << endl;
				cout <<"Armor Weight: " <<armor.getWeight() << endl;
				cout << endl;
		
		}
		catch (bad_cast) {
			try {
				const Weapon& weapon = dynamic_cast<const Weapon&>(*i);
				cout << "Weapon Name:" << weapon.getName() << endl;
				cout << "Weapon Gold Value" << weapon.getGoldValue() << endl;
				cout << "Weapon Damage" << weapon.getDamage() << endl;
				cout << "Weapon Weight:" << weapon.getWeight() << endl;
				cout << endl;

			
			
			}
			catch (bad_cast) {
				const Item& item = dynamic_cast<const Item&>(*i);

			//if not any of these then just a item
				cout << "Item Name:" << item.getName() << endl;
				cout << "Item Gold Value" << item.getGoldValue() << endl;
				cout << "Item Weight:" << item.getWeight() << endl;
				cout << endl;

			
			}
		
		}



	}
	
	for (int i = 0; i < 6; i++) {
		if (getEquippedArmor(i) == nullptr) {
			continue;
		}
		else {
			cout << "Printing Equipped Armor at slot: "<<i << endl;

			cout << "Equipped Armor Name: " << endl;
			cout << equippedArmor[i]->getName() << endl;

			cout << "Equipped Armor Slot ID: " << i << endl;
			cout << equippedArmor[i]->getSlotID() << endl;

			cout << "Equipped Armor Rating: " << endl;
			cout << equippedArmor[i]->getRating() << endl;

			cout << "Printing Equipped Armor GP Value: " << endl;
			cout << equippedArmor[i]->getGoldValue() << endl;
		}
    }
	if (getEquippedWeapon()) {
		cout << getEquippedWeapon()->getName();

		cout << getEquippedWeapon()->getDamage();
		cout << getEquippedWeapon()->getGoldValue();
		cout << getEquippedWeapon()->getWeight();
		cout << endl;


	}
	
	
	
}

const Collection<const Item>& Character::getInventory()
{
	return playerInventory;
}

void Character::addItem(const Item& item)
{   //make cases?
	
	try {

		const Armor& armor = dynamic_cast<const Armor&>(item);
		armorList.push_front(armor);
		playerInventory.add(&armorList.front());
		totalWeight += item.getWeight();

		
	}
	catch (bad_cast) {
		try {

			const Weapon& weapon = dynamic_cast<const Weapon&>(item);
			weaponList.push_front(weapon);
			playerInventory.add(&weaponList.front());
			totalWeight += item.getWeight();

		}
		catch (bad_cast) {
			try {
				itemList.push_front(item);
				playerInventory.add(&itemList.front());
				totalWeight += item.getWeight();

			}
			catch (bad_cast) {
			
			
			}

		}
	

	}





}




	

void Character::dropItem(const Item& item)
{
	//1.check what type of item they have passed in, iteratite through the right list, make sure its in the list, then get rid of it 


	if (playerInventory.getInventoryList().size() == 0) {
		throw logic_error("Inventory doesnt have anything in it");

	}
	else {
		try
		{
			playerInventory.dropItem(&item);
			totalWeight -= item.getWeight();

		}
		catch (logic_error)
		{
			throw logic_error("You are bad :(");
		}





	}
}

double Character::getTotalWeight() const
{
	return totalWeight;



}

const Armor* Character::getEquippedArmor(unsigned int slotID) const
{
	if (slotID <6 && slotID>=0) {
		return equippedArmor[slotID];
		}
	else
	{
		throw out_of_range("That Armor is not currently Equipped");
	}
}

unsigned int Character::getTotalArmorRating() const
{
	return totalArmorRating;
}

void Character::equipArmor(const Armor& armor)
{
	try {
		if (getEquippedArmor(armor.getSlotID()))
		{
			unequipArmor(armor.getSlotID());
		}
		equippedArmor[armor.getSlotID()] = &armor;
		totalArmorRating += armor.getRating();
		totalWeight += armor.getWeight();
		dropItem(armor);
	
	}
	catch (out_of_range) {
	
	
	}



	
}

void Character::unequipArmor(unsigned int slotID)
{
	
	
	if (slotID < 6 && slotID >= 0) {
		if (getEquippedArmor(slotID))
		{
			addItem(*equippedArmor[slotID]);//add it to the inventory
			totalArmorRating -= equippedArmor[slotID]->getRating();//decrase total armor rating
			totalWeight -= equippedArmor[slotID]->getWeight();//decrase total armor rating
			equippedArmor[slotID] = nullptr;//remove it from the equipped armor list
		}
		
		
		
	}
	else
	{
		throw out_of_range("The slot id given is not 0,1,2,3,4,5");
	}
}

const Weapon* Character::getEquippedWeapon() const
{

	return equippedWeapon;
}

void Character::equipWeapon(const Weapon& weapon)
{
	try {
		if (getEquippedWeapon())
		{
			unequipWeapon();
		}
		equippedWeapon = &weapon;
		totalWeight += weapon.getWeight();
		dropItem(weapon);

	}
	catch (out_of_range) {


	}
	
	
}

void Character::unequipWeapon()
{
	if (getEquippedWeapon())
	{
		addItem(*equippedWeapon);//add it to the inventory
		totalWeight -= equippedWeapon->getWeight();//decrase total armor rating
		equippedWeapon = nullptr;//remove it from the equipped armor list
	}
	
}

void Character::optimizeInventory(double maximumWeight)
{
	if (maximumWeight < 0) {
		throw out_of_range("Max Weight cant be <0");
	
	}

	while (totalWeight > maximumWeight&& playerInventory.getInventoryList().size()!=0) {
		dropItem(*(playerInventory.getInventoryList().back()));
	
	
	}
}

void Character::optimizeEquipment()
{
	


	for (auto i : playerInventory.getInventoryList()) {
		try {
			const Weapon& weapon = dynamic_cast<const Weapon&>(*i);
			if (getEquippedWeapon() == nullptr) {
				equipWeapon(weapon);
			}
			else if (weapon.getDamage() > getEquippedWeapon()->getDamage()) {
				equipWeapon(weapon);

			}


		}
		catch (bad_cast) {
			try {
				const Armor& armor = dynamic_cast<const Armor&>(*i);
				unsigned int a = armor.getSlotID();
				if (getEquippedArmor(a) == nullptr) {
					equipArmor(armor);

				}
				else if (getEquippedArmor(a)->getRating() < armor.getRating()) {
					equipArmor(armor);
				}




			}
			catch (bad_cast) {

			}

		}

	}
	for (int i = 0; i < 6; i++) {
		if (getEquippedArmor(i) == nullptr) {
			continue;
		}
		else {
			cout << "Printing Equipped Armor at slot: " << i << endl;

			cout << "Printing Equipped Armor name: " << endl;
			cout << equippedArmor[i]->getName() << endl;

			cout << "Printing Equipped Armor Slot ID: " << i << endl;
			cout << equippedArmor[i]->getSlotID() << endl;

			cout << "Printing Equipped Armor Rating: " << endl;
			cout << equippedArmor[i]->getRating() << endl;

			cout << "Printing Equipped Armor GP Value: " << i << endl;
			cout << equippedArmor[i]->getGoldValue() << endl;
		}


	}
	if (getEquippedWeapon()!=nullptr) {
		cout << "Print Equipped Weapon: " << endl;
		cout << "Name: " << getEquippedWeapon()->getName() << endl;

		cout << "Damage: " << getEquippedWeapon()->getDamage() << endl;
		cout << "Gold Value: " << getEquippedWeapon()->getGoldValue() << endl;
		cout << "Weight: " << getEquippedWeapon()->getWeight() << endl;
		cout << endl;
	}
}

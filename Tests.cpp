#include <iostream>
#include <cassert>
#include "Collection.h"
#include "Character.h"
#include "Item.h"
#include "Weapon.h"
#include "Armor.h"
#include <string>

int main() {
	int userChoice = -1;
	Character player;
	int armorSlotID = -1;
	string armorName = "";
	int armorRating = 0;
	int armorWeight = 0;
	int armorValue = 0;
	string dummy = "";
	Armor armor;
	Weapon weapon;
	string weaponName = "";
	double maxWeight = 0.0;
	double weaponWeight =0.0;
	int weaponValue = 0;
	int damage = 0;
	Item item;
	while (userChoice != 6) {

		cout << "====================================="<< endl;
		cout << "------------ RPG MANAGER ------------"<< endl;
		cout << "====================================="<< endl;
		cout << "Please Select an Option:"<< endl;
		cout << "0: Print Inventory" << endl;
		cout << "1: Add Unequippable Item"<< endl;
		cout << "2: Add Armor"<< endl;
		cout << "3: Add Weapon"<< endl;
		cout << "4: Optimize Inventory"<< endl;
		cout << "5: Optimize Equipment"<< endl;
		cout << "6: Quit"<< endl;
		cout << "====================================="<< endl;
		cout << "  Please enter a choice"<< endl;

		cin >> userChoice;

		switch (userChoice) {
		case 0:
			player.printInventory();
			break;
		case 1:

			cout << "Enter a name: " << endl;
			cin >> weaponName;
			item.setName(weaponName);
			getline(cin, dummy);
			cout << "Enter a weight: " << endl;

			cin >> armorValue;
			item.setWeight(armorValue);
			cout << "Enter GP Value: " <<endl;
			cin >> armorValue;
			item.setGoldValue(armorValue);
			player.addItem(item);
			break;
		case 2:

			
			cout<< "--------- ADD ARMOR ------------" <<endl;
			cout << "Enter the armor slot: " << endl;

			cin >> armorSlotID;
			armor.setSlotID(armorSlotID);
			
			cout << "Enter the Armor's Name: " << endl;
			cin >> armorName;
			armor.setName(armorName);
			getline(cin, dummy);
			cout << "Enter the Armor's Rating: " << endl;
            cin >> armorRating;
			armor.setRating(armorRating);
			cout << "Enter the Armor's Weight: " << endl;
			cin >> armorWeight;
			armor.setWeight(armorWeight);
			cout << "Enter the Armor's Value: " << endl;
			cin >> armorValue;
			armor.setGoldValue(armorValue);
			player.addItem(armor);
			break;
		case 3:
			
			cout << "Enter the weapon's name" << endl;
			cin >> weaponName;
			weapon.setName(weaponName);
			getline(cin, dummy);
			cout << "Enter weapon's weight" << endl;
			cin >> weaponWeight;
			weapon.setWeight(weaponWeight);
			cout << "Enter the weapon's gold value" << endl;

			cin >> weaponValue;
			weapon.setGoldValue(weaponValue);
			cout << "Enter the damage" << endl;
			cin >> damage;
			weapon.setDamage(damage);
			player.addItem(weapon);
			break;
		case 4:
			cout << "Enter the Max Weight you want" << endl;
			cin >> maxWeight;
			player.optimizeInventory(maxWeight);
			break;
		case 5:
			player.optimizeEquipment();//print out the array after words 
			break;
		case 6:
			userChoice = 6;
			break;

		}
	}


		return 0;
	};

/*using namespace std;

bool operator == (const Item& item1, const Item& item2)
{
	// Are item fields equal?
	if (item1.getGoldValue() == item2.getGoldValue()
		&& item1.getName() == item2.getName()
		&& item1.getWeight() == item2.getWeight())
	{
		try
		{
			// Is the first item a weapon?
			const Weapon& weapon1 = dynamic_cast<const Weapon&>(item1);

			try
			{
				// Is the second item a weapon?
				const Weapon& weapon2 = dynamic_cast<const Weapon&>(item2);

				// Are the damages equal?
				return weapon1.getDamage() == weapon2.getDamage();
			}
			catch (bad_cast)
			{
				// First is a weapon and second isn't, not equal
				return false;
			}
		}
		catch (bad_cast)
		{
			// First item is not a weapon
			if (dynamic_cast<const Weapon*>(&item2))
			{
				// If the second item is a weapon, return false
				return false;
			}
			else
			{
				// Neither item is a weapon
				try
				{
					// Is the first item an armor?
					const Armor& armor1 = dynamic_cast<const Armor&>(item1);

					try
					{
						// Is the second item an armor?
						const Armor& armor2 = dynamic_cast<const Armor&>(item2);

						// Are the armor attributes equal?
						return armor1.getRating() == armor2.getRating()
							&& armor1.getSlotID() == armor2.getSlotID();
					}
					catch (bad_cast)
					{
						// First item is armor, second item is not: not equal
						return false;
					}
				}
				catch (bad_cast)
				{
					// First item is not armor
					// If the second item is armor, return false
					// Otherwise, return true (generic items are equal)
					return !dynamic_cast<const Armor*>(&item2);
				}
			}
		}
	}
	else
	{
		// Item fields are not equal, return false
		return false;
	}
}

template <typename ItemType>
const ItemType& findItem(const Collection<const Item>& inventory, const ItemType& item)
{
	const ItemType* returnValue = nullptr;

	inventory.forEach([&item, &returnValue](const Item& current)
		{
			if (item == current)
			{
				returnValue = dynamic_cast<const ItemType*>(&current);
			}
		});

	assert(returnValue);
	return *returnValue;
}

void findAndDrop(Character& character, const Item& item)
{
	character.dropItem(findItem(character.getInventory(), item));
}

void findAndEquip(Character& character, const Weapon& weapon)
{
	character.equipWeapon(findItem(character.getInventory(), weapon));
}

void findAndEquip(Character& character, const Armor& armor)
{
	character.equipArmor(findItem(character.getInventory(), armor));
}

int main()
{
	Weapon mapleBow;
	mapleBow.setName("Maple Bow");
	mapleBow.setWeight(3.0);
	mapleBow.setGoldValue(50);
	mapleBow.setDamage(10);

	Weapon ironSword;
	ironSword.setName("Iron Sword");
	ironSword.setWeight(6.0);
	ironSword.setGoldValue(50);
	ironSword.setDamage(10);

	Item healingPotion;
	healingPotion.setName("Healing Potion");
	healingPotion.setWeight(0.5);
	healingPotion.setGoldValue(36);

	Item shinyNecklace;
	shinyNecklace.setName("Shiny Necklace");
	shinyNecklace.setWeight(0.5);
	shinyNecklace.setGoldValue(120);

	Armor leatherArmor;
	leatherArmor.setName("Leather Armor");
	leatherArmor.setWeight(6.0);
	leatherArmor.setGoldValue(60);
	leatherArmor.setRating(10);
	leatherArmor.setSlotID(Armor::CHEST_SLOT);

	Armor ironBreastplate;
	ironBreastplate.setName("Iron Breastplate");
	ironBreastplate.setWeight(15.0);
	ironBreastplate.setGoldValue(60);
	ironBreastplate.setRating(12);
	ironBreastplate.setSlotID(Armor::CHEST_SLOT);

	Armor ironBoots;
	ironBoots.setName("Iron Boots");
	ironBoots.setWeight(3.0);
	ironBoots.setGoldValue(25);
	ironBoots.setRating(10);
	ironBoots.setSlotID(Armor::FEET_SLOT);

	Item ironOre;
	ironOre.setName("Iron Ore");
	ironOre.setWeight(10.0);
	ironOre.setGoldValue(20);


	Armor leatherPants;
	leatherPants.setName("Leather Pants");
	leatherPants.setWeight(6.0);
	leatherArmor.setGoldValue(60);
	leatherPants.setRating(10);
	leatherPants.setSlotID(Armor::LEGS_SLOT);

	Armor steelGauntlets;
	steelGauntlets.setName("Steel Gauntlets");
	steelGauntlets.setWeight(4.0);
	steelGauntlets.setGoldValue(55);
	steelGauntlets.setRating(12);
	steelGauntlets.setSlotID(Armor::HANDS_SLOT);

	Armor legendaryBoots;
	legendaryBoots.setName("Legendary Boots");
	legendaryBoots.setWeight(8.0);
	legendaryBoots.setGoldValue(425);
	legendaryBoots.setRating(17);
	legendaryBoots.setSlotID(Armor::FEET_SLOT);

	Armor dwarvenHelmet;
	dwarvenHelmet.setName("Dwarven Helmet");
	dwarvenHelmet.setWeight(12.0);
	dwarvenHelmet.setGoldValue(200);
	dwarvenHelmet.setRating(18);
	dwarvenHelmet.setSlotID(Armor::HEAD_SLOT);

	Armor woodenShield;
	woodenShield.setName("Wooden Shield");
	woodenShield.setWeight(6.0);
	woodenShield.setGoldValue(30);
	woodenShield.setRating(10);
	woodenShield.setSlotID(Armor::SHIELD_SLOT);

	Weapon steelGreatsword;
	steelGreatsword.setName("Steel Greatsword");
	steelGreatsword.setWeight(17.0);
	steelGreatsword.setGoldValue(90);
	steelGreatsword.setDamage(17);

	Item magicPotion;
	magicPotion.setName("Magic Potion");
	magicPotion.setWeight(0.5);
	magicPotion.setGoldValue(44);

	Armor legendaryBreastplate;
	legendaryBreastplate.setName("Legendary Breastplate");
	legendaryBreastplate.setWeight(7.0);
	legendaryBreastplate.setGoldValue(525);
	legendaryBreastplate.setRating(17);
	legendaryBreastplate.setSlotID(Armor::CHEST_SLOT);

	Weapon legendaryBattleaxe;
	legendaryBattleaxe.setName("Legendary Battleaxe");
	legendaryBattleaxe.setWeight(30);
	legendaryBattleaxe.setGoldValue(3000);
	legendaryBattleaxe.setDamage(26);

	Armor armorSet[Armor::SLOT_COUNT];
	for (unsigned int i = 0; i < Armor::SLOT_COUNT; i++)
	{
		armorSet[i].setName("Leather Armor");
		armorSet[i].setWeight(6.0);
		armorSet[i].setGoldValue(60);
		armorSet[i].setRating(10);
		armorSet[i].setSlotID(i);
	}

	//setup
	{
		Character character;

		assert(character.getTotalWeight() == 0);
		assert(character.getEquippedWeapon() == nullptr);
		assert(character.getTotalArmorRating() == 0);
		for (int i = 0; i < 6; i++)
		{
			assert(character.getEquippedArmor(i) == nullptr);
		}
	}

	// add item
	{
		Character character;

		// Load the example as in the spec sheet
		character.addItem(mapleBow);
		character.addItem(healingPotion);
		character.addItem(shinyNecklace);
		character.addItem(leatherArmor);
		character.addItem(ironBoots);
		character.addItem(ironOre);
		character.addItem(ironOre);

		assert(character.getTotalWeight() == 33);
		assert(!character.getEquippedWeapon());
		for (unsigned int i = 0; i < Armor::SLOT_COUNT; i++)
		{
			assert(!character.getEquippedArmor(i));
		}
	}

	// inventory
	{
		Character character;

		character.addItem(mapleBow);
		character.addItem(healingPotion);
		character.addItem(shinyNecklace);
		character.addItem(leatherArmor);
		character.addItem(ironBoots);
		character.addItem(ironOre);

		assert(character.getTotalWeight() == 23);
		const Collection<const Item>& inventory = character.getInventory();
		string expected[6]{ "Shiny Necklace","Healing Potion",
			"Maple Bow", "Leather Armor", "Iron Boots", "Iron Ore" };

		unsigned int i = 0;

		inventory.forEach([&expected, &i](const Item& item)
			{
				assert(item.getName() == expected[i]);
				i++;
			});
	}

	// drop - item not found
	try
	{
		Character character;
		character.dropItem(mapleBow);
		assert(false);
	}
	catch (logic_error)
	{
	}

	// Trying to drop the template that was added
	try
	{
		Character character;
		character.addItem(mapleBow);
		character.dropItem(mapleBow);
		assert(false);
	}
	catch (logic_error)
	{
	}

	// Single weapon that is added and dropped.
	{
		Character character;
		character.addItem(mapleBow);
		assert(character.getTotalWeight() == 3.0);
		const Item& realWeapon = findItem(character.getInventory(), mapleBow);
		character.dropItem(realWeapon);
		assert(character.getTotalWeight() == 0);

		try
		{
			character.dropItem(realWeapon);
			assert(false);
		}
		catch (logic_error)
		{
		}
	}

	// drop multiple items
	{
		Character character;
		character.addItem(mapleBow);
		character.addItem(leatherArmor);
		character.addItem(ironBoots);
		character.addItem(ironOre);
		character.addItem(ironOre);
		assert(character.getTotalWeight() == 32);

		findAndDrop(character, leatherArmor);
		assert(character.getTotalWeight() == 26);
		findAndDrop(character, ironOre);
		assert(character.getTotalWeight() == 16);

		try
		{
			character.dropItem(ironOre);
			assert(false);
		}
		catch (logic_error)
		{
		}

		assert(character.getTotalWeight() == 16);
	}

	// get total weight
	{
		Character character;
		assert(character.getTotalWeight() == 0);

		character.addItem(ironOre);
		character.addItem(mapleBow);
		character.addItem(leatherArmor);
		assert(character.getTotalWeight() == 19);

		character.addItem(ironOre);
		character.addItem(mapleBow);
		character.addItem(leatherArmor);
		assert(character.getTotalWeight() == 38);

		// drop items
		const Item& ironOreReal = findItem(character.getInventory(), ironOre);
		character.dropItem(ironOreReal);
		findAndDrop(character, mapleBow);
		findAndDrop(character, leatherArmor);
		assert(character.getTotalWeight() == 19);

		// drop again, should not change weight
		try
		{
			character.dropItem(ironOreReal);
			assert(false);
		}
		catch (logic_error)
		{
			assert(character.getTotalWeight() == 19);
		}
	}

	// equipped armor exceptions
	try
	{
		Character character;
		character.getEquippedArmor(Armor::SLOT_COUNT);
		assert(false);
	}
	catch (out_of_range)
	{
	}

	try
	{
		Character character;
		character.getEquippedArmor(77);
		assert(false);
	}
	catch (out_of_range)
	{
	}

	// equip armor
	{
		Character character;

		for (unsigned int i = 0; i < Armor::SLOT_COUNT; i++)
		{
			character.addItem(armorSet[i]);
		}

		assert(character.getTotalWeight() == 6.0 * Armor::SLOT_COUNT);

		for (unsigned int i = 0; i < Armor::SLOT_COUNT; i++)
		{
			assert(!character.getEquippedArmor(i));
			findAndEquip(character, armorSet[i]);
			assert(character.getEquippedArmor(i));
			assert(*character.getEquippedArmor(i) == armorSet[i]);
		}

		assert(character.getTotalWeight() == 6.0 * Armor::SLOT_COUNT);

		try
		{
			character.dropItem(*character.getEquippedArmor(Armor::CHEST_SLOT));
			assert(false);
		}
		catch (logic_error)
		{
		}

		assert(character.getTotalWeight() == 6.0 * Armor::SLOT_COUNT);

		assert(character.getEquippedArmor(Armor::CHEST_SLOT));
		character.unequipArmor(Armor::CHEST_SLOT);
		assert(!character.getEquippedArmor(Armor::CHEST_SLOT));
		findAndDrop(character, armorSet[Armor::CHEST_SLOT]);
		assert(!character.getEquippedArmor(Armor::CHEST_SLOT));
		character.addItem(armorSet[Armor::CHEST_SLOT]);
		assert(!character.getEquippedArmor(Armor::CHEST_SLOT));
		assert(character.getTotalWeight() == 6.0 * Armor::SLOT_COUNT);
	}

	// get total armor rating
	{
		Character character;

		for (unsigned int i = 0; i < Armor::SLOT_COUNT; i++)
		{
			assert(!character.getEquippedArmor(i));
			character.addItem(armorSet[i]);
			assert(!character.getEquippedArmor(i));
			findAndEquip(character, armorSet[i]);
			assert(character.getEquippedArmor(i));
		}

		assert(character.getTotalArmorRating() == 60);

		try
		{
			character.dropItem(*character.getEquippedArmor(Armor::CHEST_SLOT));
			assert(false);
		}
		catch (logic_error)
		{
		}
		assert(character.getEquippedArmor(Armor::CHEST_SLOT));

		character.unequipArmor(Armor::HEAD_SLOT);
		assert(character.getTotalArmorRating() == 50);
		assert(!character.getEquippedArmor(Armor::HEAD_SLOT));
		findAndDrop(character, armorSet[Armor::HEAD_SLOT]);
		assert(!character.getEquippedArmor(Armor::HEAD_SLOT));
		assert(character.getEquippedArmor(Armor::CHEST_SLOT));
		character.addItem(armorSet[Armor::CHEST_SLOT]);
		assert(character.getEquippedArmor(Armor::CHEST_SLOT));
	}

	// equip armor 2
	{
		Character character;
		character.addItem(leatherArmor);
		findAndEquip(character, leatherArmor);
		assert(character.getTotalArmorRating() == 10);
		assert(character.getEquippedArmor(0));
		assert(*character.getEquippedArmor(0) == leatherArmor);

		for (unsigned int i = 1; i < Armor::SLOT_COUNT; i++)
		{
			assert(!character.getEquippedArmor(i));
		}
	}

	// unequip armor exceptions
	try
	{
		Character character;
		character.unequipArmor(Armor::SLOT_COUNT);
		assert(false);
	}
	catch (out_of_range)
	{
	}

	try
	{
		Character character;
		character.unequipArmor(77);
		assert(false);
	}
	catch (out_of_range)
	{
	}

	// unequip armor
	{
		Character character;

		for (unsigned int i = 0; i < Armor::SLOT_COUNT; i++)
		{
			assert(!character.getEquippedArmor(i));
			character.addItem(armorSet[i]);
			assert(!character.getEquippedArmor(i));
			findAndEquip(character, armorSet[i]);
			assert(character.getEquippedArmor(i));
		}

		character.unequipArmor(Armor::CHEST_SLOT);
		assert(character.getTotalArmorRating() == 50);

		for (unsigned int i = 0; i < 5; i++)
		{
			character.unequipArmor(Armor::CHEST_SLOT);
			assert(character.getTotalArmorRating() == 50);
		}
	}

	// equip weapon 1
	{
		Character character;
		try
		{
			character.equipWeapon(mapleBow);
			assert("false");
		}
		catch (logic_error)
		{
		}

		character.addItem(mapleBow);
		findAndEquip(character, mapleBow);

		assert(character.getEquippedWeapon());
		assert(*character.getEquippedWeapon() == mapleBow);
	}

	// equip weapon 2
	{
		Character character;
		character.addItem(mapleBow);
		assert(character.getTotalWeight() == 3.0);
		findAndEquip(character, mapleBow);
		assert(character.getTotalWeight() == 3.0);
		character.addItem(ironSword);
		assert(character.getTotalWeight() == 9.0);
	}

	// unequip weapon
	{
		Character character;
		character.addItem(ironSword);
		findAndEquip(character, ironSword);
		assert(*character.getEquippedWeapon() == ironSword);
		character.unequipWeapon();
		assert(character.getTotalWeight() == 6.0);
		character.unequipWeapon();
		assert(character.getTotalWeight() == 6.0);
	}


	// equip weapon 3
	{
		Character character;

		character.addItem(mapleBow);
		assert(character.getTotalWeight() == 3.0);
		findAndEquip(character, mapleBow);
		assert(character.getTotalWeight() == 3.0);
		assert(*character.getEquippedWeapon() == mapleBow);

		character.addItem(ironSword);
		character.unequipWeapon();
		assert(character.getTotalWeight() == 9.0);

		findAndEquip(character, ironSword);
		assert(*character.getEquippedWeapon() == ironSword);

		character.optimizeInventory(0); // drop all unequipped items
		assert(*character.getEquippedWeapon() == ironSword);
		character.unequipWeapon();
		assert(character.getTotalWeight() == 6.0);
		character.optimizeInventory(0); // should have no items left
		assert(character.getTotalWeight() == 0.0);
	}

	// optimize inventory
	{
		Character character;

		for (unsigned int i = 0; i < 10; i++)
		{
			character.addItem(ironBreastplate);
		}

		assert(character.getTotalWeight() == 150);

		character.optimizeInventory(140);
		assert(character.getTotalWeight() == 135);

		character.optimizeInventory(80);
		assert(character.getTotalWeight() == 75);

		character.optimizeInventory(75);
		assert(character.getTotalWeight() == 75);

		character.optimizeInventory(10);
		assert(character.getTotalWeight() == 0);

		character.addItem(ironBreastplate);
		assert(character.getTotalWeight() == 15);

		try
		{
			character.optimizeInventory(-1);
			assert(false);
		}
		catch (out_of_range)
		{
		}

		assert(character.getTotalWeight() == 15);
	}

	// gigantic test (includes optimize equipment)
	{
		Character character;
		character.addItem(mapleBow);
		character.addItem(healingPotion);
		character.addItem(shinyNecklace);
		character.addItem(leatherArmor);
		character.addItem(ironBoots);
		character.addItem(ironOre);
		assert(character.getTotalWeight() == 23);
		assert(character.getInventory().getSize() == 6);

		string expected[6] = { "Shiny Necklace","Healing Potion", "Maple Bow", "Leather Armor", "Iron Boots","Iron Ore" };
		unsigned int i = 0;
		character.getInventory().forEach([&expected, &i](const Item& item)
			{
				assert(item.getName() == expected[i]);
				i++;
			});

		character.addItem(ironBreastplate);
		character.addItem(leatherPants);
		character.addItem(steelGauntlets);
		character.addItem(legendaryBoots);
		character.addItem(dwarvenHelmet);
		character.addItem(woodenShield);
		assert(character.getTotalWeight() == 74);

		findAndEquip(character, ironBreastplate);
		findAndEquip(character, leatherPants);
		findAndEquip(character, steelGauntlets);
		findAndEquip(character, legendaryBoots);
		findAndEquip(character, dwarvenHelmet);
		findAndEquip(character, woodenShield);
		assert(character.getTotalArmorRating() == 79);

		character.addItem(steelGreatsword);
		findAndEquip(character, steelGreatsword);
		assert(character.getEquippedWeapon());
		assert(*character.getEquippedWeapon() == steelGreatsword);

		assert(character.getInventory().getSize() == 6);
		i = 0;
		character.getInventory().forEach([&expected, &i](const Item& item)
			{
				assert(item.getName() == expected[i]);
				i++;
			});

		for (unsigned int i = 0; i < Armor::SLOT_COUNT; i++)
		{
			assert(character.getEquippedArmor(i));
		}

		assert(character.getTotalWeight() == 91);

		character.addItem(magicPotion);
		character.addItem(legendaryBreastplate);
		character.addItem(legendaryBattleaxe);

		string expected2[9] = { "Shiny Necklace","Legendary Battleaxe","Magic Potion", "Legendary Breastplate","Healing Potion","Maple Bow", "Leather Armor", "Iron Boots","Iron Ore" };
		i = 0;
		assert(character.getInventory().getSize() == 9);
		character.getInventory().forEach([&expected2, &i](const Item& item)
			{
				assert(item.getName() == expected2[i]);
				i++;
			});

		character.optimizeInventory(110.0);
		assert(character.getTotalWeight() == 109.5);

		assert(character.getInventory().getSize() == 6);
		i = 0;
		character.getInventory().forEach([&expected2, &i](const Item& item)
			{
				assert(item.getName() == expected2[i]);
				i++;
			});

		character.optimizeEquipment();
		assert(character.getTotalWeight() == 109.5);
		assert(character.getTotalArmorRating() == 84);
		assert(*character.getEquippedWeapon() == legendaryBattleaxe);
		assert(*character.getEquippedArmor(0) == legendaryBreastplate);

		bool found = false;
		character.getInventory().forEach([&found, ironBreastplate](const Item& item)
			{
				found = found || (item == ironBreastplate);
			});

		assert(found);
	}

	cout << "ALL TESTS PASSED" << endl;

	return 0;
}*/
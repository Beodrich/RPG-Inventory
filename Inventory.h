#pragma once
#include "Collection.h"
#include "Item.h"
#include <functional>
#include <list>
using namespace std;
class Inventory : public Collection<const Item>
{
public:
	const list<const Item*> getInventoryList()const {

		return inventoryList;
	};
	bool compareGoldToWeight();
	virtual unsigned int getSize() const override
	{
		return size;
	};

	 void forEach(
		 const function<void(const Item&)>& accept)
		 const override
	 {
		 for (auto i : inventoryList) {
			 accept(*i);
		 
		 }
	 };

	 void forEach(
		 const function<void(const Item&)>& accept)override
	 {
		 for (auto i : inventoryList) {
			 accept(*i);

		 }
	 };
	
	 
	 
	 void add(const Item* item)
	 {
		

		 double itemGoldToWeight = (double)(*item).getGoldValue() / (*item).getWeight();
		 auto invetoryIterator = inventoryList.begin();
		 for (auto i: inventoryList) {
			 double currentIRatio = (double)(i)->getGoldValue() / (i)->getWeight();
			 if (itemGoldToWeight < currentIRatio) {
				 invetoryIterator++;//iterate to figure out were to insert it into the list
			   
			 }
		 
		 
		 }
		 inventoryList.insert(invetoryIterator, item);

		 ++size;

		};
	 

	 const 	Item* getFirst() const
	 {
		 return inventoryList.front();
	 };
	 void dropItem(const Item* item)
	 {
		 bool isItemFound = false; 
		 for (auto i : inventoryList) {
			 if (item == i) {
				 //found the item
				 isItemFound = true;
				 break;
			 }
		 }
		 if (isItemFound == true) {

			 inventoryList.remove(item);
			 --size;
		 }
		 else {
		 
			 throw logic_error("Item not found");
		 }
	 };
private: 
	unsigned int size = 0; 
	list<const Item*> inventoryList;


};





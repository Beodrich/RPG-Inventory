#include "Item.h"

Item::~Item()
{
}

std::string Item::getName() const
{
    return name;
}

unsigned int Item::getGoldValue() const
{
    return goldValue;
}

double Item::getWeight() const
{
    return weight;
}

void Item::setName(std::string name)
{
    this->name = name;
}

void Item::setGoldValue(unsigned int goldValue)
{
    this->goldValue = goldValue;
}

void Item::setWeight(double weight)
{
    this->weight = weight;
}

bool Item::operator==(Item other)
{
	return false;
}

#pragma once
#include <string>

class Item
{
public:
    virtual ~Item();

    std::string getName() const;
    unsigned int getGoldValue() const;
    double getWeight() const;

    void setName(std::string name);
    void setGoldValue(unsigned int goldValue);
    void setWeight(double weight);
	bool operator ==(Item other);
private:
    std::string name { "Item" };
    unsigned int goldValue { 0 };
    double weight { 0.0 };
};

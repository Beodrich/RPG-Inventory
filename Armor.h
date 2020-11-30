#pragma once
#include "Item.h"

class Armor : public Item
{
public:
    unsigned int getSlotID() const;
    int getRating() const;

    void setSlotID(unsigned int slotID);
    void setRating(int rating);

    const static unsigned int  CHEST_SLOT = 0;
    const static unsigned int   LEGS_SLOT = 1;
    const static unsigned int  HANDS_SLOT = 2;
    const static unsigned int   FEET_SLOT = 3;
    const static unsigned int   HEAD_SLOT = 4;
    const static unsigned int SHIELD_SLOT = 5;
    const static unsigned int  SLOT_COUNT = 6;

private:
    unsigned int slotID { CHEST_SLOT };
    int rating { 0 };
};
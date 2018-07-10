//
//  Item.hpp
//  TextGame
//
//  Created by Derek Critchfield on 5/4/16.
//  Copyright © 2016 Derek Critchfield. All rights reserved.
//

#ifndef Item_hpp
#define Item_hpp

#pragma once

#include <iostream>
#include <sstream>
#include "OtherFunctions.hpp"

using namespace std;

/*
 * Item
 * Header File
 * Manages all attributes of items within the game includes function to load items from a string stream
 */
class Item {
private:
    string name;
    string description;
    string openWith;
    string combineWith;
    bool isEquipable;
    bool isEquipped;
    bool isDamaged;
    bool isUseable;
    bool isUsed;
    bool isOpenable;
    bool isOpen;
    int healthAdd;
    int armorAdd;
    int blockAdd;
    int attackAdd;
    OtherFunctions myOtherFunc;
    
public:
    Item();
    ~Item();
    void loadItem(istringstream& stream);
    
    //getters and setters
    string getName();
    void setName(string nName);
    string getDescription();
    void setDescription(string nDes);
    string getOpenWith();
    void setOpenWith(string nOpenW);
    string getCombineWith();
    void setCombineWith(string nCombW);
    string getLocationType();
    void setLocationType(string nLocT);
    bool getIsEquipable();
    void setIsEquipable(bool isE);
    bool getIsEquipped();
    void setIsEquipped(bool isE);
    bool getIsDamaged();
    void setIsDamaged(bool isD);
    bool getIsUseable();
    void setIsUseable(bool isU);
    bool getIsUsed();
    void setIsUsed(bool isUd);
    bool getIsOpenable();
    void setIsOpenable(bool isOpenA);
    bool getIsOpen();
    void setIsOpen(bool isOp);
    int getHealthAdd();
    void setHealthAdd(int hlthA);
    int getArmorAdd();
    void setArmorAdd(int armA);
    int getBlockAdd();
    void setBlockAdd(int blkA);
    int getAttackAdd();
    void setAttackAdd(int atkA);
    
};

#endif /* Item_hpp */

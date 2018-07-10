//
//  Item.cpp
//  TextGame
//
//  Created by Derek Critchfield on 5/4/16.
//  Copyright © 2016 Derek Critchfield. All rights reserved.
//

#include "Item.hpp"

/*
 * Item
 * Implementation
 */

// Constructor sets intial value for name and isEquipped and isFalse values to false for new items
Item::Item()
:name("NO NAME"),
 isEquipped(false),
 isUsed(false){

}

// Deconstructor no memory management needed since no memory is allocated within this class
Item::~Item(){
    
}

// Loads Items from a formatted string stream setting necessary attributes
void Item::loadItem(istringstream& stream){
    string garbage = "";
    string tempStr = "";
    stream >> garbage;
    stream >> ws;
    getline(stream, name);
    stream >> garbage;
    stream >> ws;
    getline(stream, description);
    stream >> garbage;
    stream >> ws;
    getline(stream, openWith);
    stream >> garbage;
    stream >> ws;
    getline(stream, combineWith);
    stream >> garbage;
    stream >> ws;
    getline(stream, tempStr);
    isEquipable = myOtherFunc.getBoolFromString(tempStr);
    stream >> garbage;
    stream >> ws;
    getline(stream, tempStr);
    isDamaged = myOtherFunc.getBoolFromString(tempStr);
    stream >> garbage;
    stream >> ws;
    getline(stream, tempStr);
    isUseable = myOtherFunc.getBoolFromString(tempStr);
    stream >> garbage;
    stream >> ws;
    getline(stream, tempStr);
    isOpenable = myOtherFunc.getBoolFromString(tempStr);
    stream >> garbage;
    stream >> ws;
    getline(stream, tempStr);
    isOpen = myOtherFunc.getBoolFromString(tempStr);
    stream >> garbage >> ws >> healthAdd;
    stream >> garbage >> ws >> armorAdd;
    stream >> garbage >> ws >> blockAdd;
    stream >> garbage >> ws >> attackAdd;
    stream >> ws;
}

// getters and setters
string Item::getName(){
    return name;
}

void Item::setName(string nName){
    name = nName;
}

string Item::getDescription(){
    return description;
}

void Item::setDescription(string nDes){
    description = nDes;
}

string Item::getOpenWith(){
    return openWith;
}

void Item::setOpenWith(string nOpenW){
    openWith = nOpenW;
}

string Item::getCombineWith(){
    return combineWith;
}

void Item::setCombineWith(string nCombW){
    combineWith = nCombW;
}

bool Item::getIsEquipable(){
    return isEquipable;
}

void Item::setIsEquipable(bool isE){
    isEquipable = isE;
}

bool Item::getIsEquipped(){
    return isEquipped;
}

void Item::setIsEquipped(bool isEd){
    isEquipped = isEd;
    if(isEquipped){
        name.append("(E)");
    }else{
        name.erase(name.end()-3, name.end());
    }
}

bool Item::getIsDamaged(){
    return isDamaged;
}

void Item::setIsDamaged(bool isD){
    isDamaged = isD;
}

bool Item::getIsUseable(){
    return isUseable;
}

void Item::setIsUseable(bool isU){
    isUseable = isU;
}

bool Item::getIsUsed(){
    return isUsed;
}
void Item::setIsUsed(bool isUd){
    isUsed = isUd;
}

bool Item::getIsOpenable(){
    return isOpenable;
}

void Item::setIsOpenable(bool isOpenA){
    isOpenable = isOpenA;
}

bool Item::getIsOpen(){
    return isOpen;
}

void Item::setIsOpen(bool isOp){
    isOpen = isOp;
}

int Item::getHealthAdd(){
    return healthAdd;
}

void Item::setHealthAdd(int hlthA){
    healthAdd = hlthA;
}

int Item::getArmorAdd(){
    return armorAdd;
}

void Item::setArmorAdd(int armA){
    armorAdd = armA;
}

int Item::getBlockAdd(){
    return blockAdd;
}

void Item::setBlockAdd(int blkA){
    blockAdd = blkA;
}

int Item::getAttackAdd(){
    return attackAdd;
}

void Item::setAttackAdd(int atkA){
    attackAdd = atkA;
}


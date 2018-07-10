//
//  Player.cpp
//  TextGame
//
//  Created by Derek Critchfield on 5/4/16.
//  Copyright © 2016 Derek Critchfield. All rights reserved.
//

#include "Player.hpp"

/*
 * Player
 * Implementation
 */

// Constructor assigns base attributes for all starting players. Also reserves space in the inventory vector
// for the players inventoryCapacity
Player::Player()
:name("NO NAME"),
 maxHealth(50),
 health(maxHealth),
 isAlive(true),
 level(1),
 armor(0),
 block(0),
 attack(5),
 inventoryCapacity(4)
{
    inventory.reserve(inventoryCapacity);
}

// Deconstructor no memory management needed since no memory is allocated within this class
Player::~Player(){
}


// Adds an item to the players inventory returns false if the inventory is at full capacity
bool Player::addItemToInventory(Item newInventoryItem){
    if (inventory.size() < inventoryCapacity){
        inventory.push_back(newInventoryItem);
        return true;
    }else {
        return false;
    }
}

// prints the players attributes and inventory items
void Player::describe(){
    cout << endl;
    cout << name << endl;
    cout << "----------------------------" << endl;
    cout << "Level: " << level << endl;
    cout << "Health: " << health << "(" << maxHealth << ")" << endl;
    cout << "Attack: " << attack << endl;
    cout << "Armor: " << armor << endl;
    cout << "Block: " << block << endl;
    cout << "Inventory: " << inventory.size() << "(" << inventoryCapacity << ")" << endl;
    cout << "----------------------------" << endl;
    cout << "Inventory:" << endl;
    if (inventory.size() == 0){
        cout << "YOU CURRENTLY HAVE NO ITEMS" << endl;
    }
    for (int i = 0; i < inventory.size(); i ++){
        cout << inventory[i].getName() << endl;
    }
    cout << endl;
    cout << "----------------------------" << endl;
    
}

// getters and setters
string Player::getName(){
    return name;
}

void Player::setName(string nName){
    name = nName;
}

int Player::getTotalPossibleHealth(){
    return maxHealth;
}

void Player::setTotalPossibleHealth(int nMxHlth){
    maxHealth = nMxHlth;
}

int Player::getHealth(){
    return health;
}

void Player::setHealth(int nHlth){
    health = nHlth;
}

bool Player::getIsAlive(){
    return isAlive;
}

void Player::setIsAlive(bool nIsAlive){
    isAlive = nIsAlive;
}

int Player::getLevel(){
    return level;
}

void Player::setLevel(int nLevel){
    level = nLevel;
}

int Player::getArmor(){
    return armor;
}

void Player::setArmor(int nArm){
    armor = nArm;
}

int Player::getBlock(){
    return block;
}

void Player::setBlock(int nBlk){
    block = nBlk;
}

int Player::getAttack(){
    return attack;
}

void Player::setAttack(int nAtk){
    attack = nAtk;
}

int Player::getInventoryCapacity(){
    return inventoryCapacity;
}

void Player::setInventoryCapacity(int nInvCap){
    inventoryCapacity = nInvCap;
}

vector<Item>* Player::getInventoryVector(){
    return &inventory;
}

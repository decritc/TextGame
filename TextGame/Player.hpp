//
//  Player.hpp
//  TextGame
//
//  Created by Derek Critchfield on 5/4/16.
//  Copyright © 2016 Derek Critchfield. All rights reserved.
//

#ifndef Player_hpp
#define Player_hpp

#pragma once

#include <iostream>
#include "Item.hpp" 
#include <vector>

using namespace std;

/*
 * Player
 * Header File
 * Manages the player attributes and inventory. Has functions to display the users attributes and inventory 
 * and functions for adding items to the players inventory while maintaining capacity limits.
 */

class Player {
private:
    string name;
    int maxHealth;
    int health;
    bool isAlive;
    int level;
    int armor;
    int block;
    int attack;
    int inventoryCapacity;
    vector<Item> inventory;
    
public:
    Player();
    ~Player();
    bool addItemToInventory(Item newInventoryItem);
    void describe();

    //getters and setters
    string getName();
    void setName(string nName);
    int getTotalPossibleHealth();
    void setTotalPossibleHealth(int nMxHlth);
    int getHealth();
    void setHealth(int nHlth);
    bool getIsAlive();
    void setIsAlive(bool nIsAlive);
    int getLevel();
    void setLevel(int nLevel);
    int getArmor();
    void setArmor(int nArm);
    int getBlock();
    void setBlock(int nBlk);
    int getAttack();
    void setAttack(int nAtk);
    int getInventoryCapacity();
    void setInventoryCapacity(int nInvCap);
    vector<Item>* getInventoryVector();
};
#endif /* Player_hpp */

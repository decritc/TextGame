//
//  Room.hpp
//  TextGame
//
//  Created by Derek Critchfield on 5/4/16.
//  Copyright © 2016 Derek Critchfield. All rights reserved.
//

#ifndef Room_hpp
#define Room_hpp

#pragma once

#include <iostream>
#include <sstream>
#include "OtherFunctions.hpp"

using namespace std;

/*
 * Room
 * Object class that holds attributes for the rooms used within the game includes a fuction to load rooms from 
 * a string
 */
class Room {
private:
    string name;
    string description;
    Room* enterRoom;
    Room* exitRoom1;
    Room* exitRoom2;
    Room* exitRoom3;
    string itemsContained;
    string enemiesContained;
    int numberItems;
    int numberEnemies;
    direction enterDirection;
    direction exitDirection1;
    direction exitDirection2;
    direction exitDirection3;
    int numberExits;
    roomType rType;
    int roomCordX;
    int roomCordY;
    bool hasBeenEntered;
    OtherFunctions myOtherFunc;
    
public:
    Room();
    ~Room();
    void loadRoom(istringstream& stream);
    
    //getters and setters
    string getName();
    void setName(string nName);
    string getDescription();
    void setDescription(string nDes);
    Room* getEnterRoom();
    void setEnterRoom(Room* nER);
    Room* getExitRoom1();
    void setExitRoom1(Room* nXR1);
    Room* getExitRoom2();
    void setExitRoom2(Room* nXR2);
    Room* getExitRoom3();
    void setExitRoom3(Room* nXR3);
    string getItemsContained();
    void setItemsContained(string nIC);
    string getEnemiesContained();
    void setEnemiesContained(string nEC);
    int getNumberItems();
    void setNumberItems(int nIt);
    int getNumberEnemies();
    void setNumberEnemies(int nEn);
    direction getEnterDirection();
    void setEnterDirection(direction nED);
    direction getExitDirection1();
    void setExitDirection1(direction nXD1);
    direction getExitDirection2();
    void setExitDirection2(direction nXD2);
    direction getExitDirection3();
    void setExitDirection3(direction nXD3);
    int getNumberExits();
    void setNumberExits(int nEx);
    roomType getRType();
    void setRType(roomType nRT);
    int getRoomCordX();
    void setRoomCordX(int nRCX);
    int getRoomCordY();
    void setRoomCordY(int nRCY);
    bool getHasBeenEntered();
    void setHasBeenEntered(bool nHBE);

    
};


#endif /* Room_hpp */

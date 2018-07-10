//
//  Map.hpp
//  TextGame
//
//  Created by Derek Critchfield on 5/4/16.
//  Copyright © 2016 Derek Critchfield. All rights reserved.
//

#ifndef Map_hpp
#define Map_hpp

#pragma once

#include <iostream>
#include "Room.hpp"
#include "Enemy.hpp"
#include "OtherFunctions.hpp"
#include <sstream>
#include <vector>

using namespace std;

/*
 * Map
 * Header File
 * Class that sets up and manages all aspects of the Map and controls the room values. Additional details 
 * about each function are within the implementation file.
 */
class Map {
private:
    vector<Room> lRooms;
    vector<Enemy> lEnemies;
    vector<Item> lItems;
    Room** level;
    unsigned const ROW;
    unsigned const COLUMN;
    unsigned const ATTEMPTMAX;
    unsigned int attemptCount;
    OtherFunctions myFunctions;
    Room newRoom;
    Enemy newEnemy;
    Item newItem;
    Room* roomPtr;
    unsigned int numRooms;
    unsigned int numEnemies;
    unsigned int numItems;
    
    // private functions only used within class
    void loadRooms();
    void loadEnemies();
    void loadItems();
    void setPath();
    
    
public:
    Map();
    ~Map();
    void resetLevel();
    void generateLevel();
    void printLevel();
    
    // getters and setters
    Room* getRoomPtr();
    void setRoomPtr(Room* currRoom);
    vector<Enemy> getlEnemies();
    vector<Item> getlItems();
};
#endif /* Map_hpp */

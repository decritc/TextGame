//
//  GameManager.hpp
//  TextGame
//
//  Created by Derek Critchfield on 5/4/16.
//  Copyright © 2016 Derek Critchfield. All rights reserved.
//

#ifndef GameManager_hpp
#define GameManager_hpp

#pragma once

#include <iostream>
#include <algorithm>

#include "CinReader.h"
#include "OtherFunctions.hpp"
#include "Player.hpp"
#include "Map.hpp"

using namespace std;

/*
 * GameManager
 * Header File
 * Contains the main game loop handling all user interaction as well as damage calculations for fights and
 * returns to the main loop when player dies within the playGame fuction. Additional breakdown of how it works
 * is within the implementation file.
 */

class GameManager {
private:
    Map myMap;
    CinReader reader;
    string userInput;
    int numOfStars;
    int randEnemyType;
    int randItemType;
    Room* lastRoom;
    vector<Enemy> currEnemy;
    vector<Item> currItem;
    OtherFunctions myOtherFunc;
public:
    GameManager();
    ~GameManager();
    bool playGame(Player currPlayer);
};

#endif /* GameManager_hpp */

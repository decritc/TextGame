//
//  OtherFunctions.hpp
//  TextGame
//
//  Created by Derek Critchfield on 5/4/16.
//  Copyright © 2016 Derek Critchfield. All rights reserved.
//

#ifndef OtherFunctions_hpp
#define OtherFunctions_hpp

#pragma once

#include <iostream>
#include <time.h>
#include <fstream>
#include <map>

using namespace std;

enum direction {NORTH, SOUTH, EAST, WEST, NODIR};
enum roomType {START, EXIT, CORRIDOR, FORK, DEAD, NONE};

/*
 * OtherFunctions
 * Usefull functions for use through the program such as random number generation, file loading, string 
 * conversions, and mapping of directions and roomTypes.
 */

class OtherFunctions {
private:
    int randNum;
    string fileStr;
    long oldseed;
    int randDir;
    map <string,roomType> dictionary;
    map <direction,string> directionDict;
public:
    OtherFunctions();
    ~OtherFunctions();
    int getRandNum(int min, int max);
    string loadFile(string fileName);
    direction getRandDir();
    string getStrFromRoomType(direction dirTStr);
    roomType getRoomTypeFromString(string rTStr);
    bool getBoolFromString(string bStr);
};
#endif /* OtherFunctions_hpp */

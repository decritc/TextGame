//
//  OtherFunctions.cpp
//  TextGame
//
//  Created by Derek Critchfield on 5/4/16.
//  Copyright © 2016 Derek Critchfield. All rights reserved.
//

#include "OtherFunctions.hpp"

/*
 * OtherFunctions
 * Implementation
 */

// Constructor sets up dictionary's for the room type and direction list as well as assigns the randNum variable
// an initial value of zero and the fileStr an empty string
OtherFunctions::OtherFunctions()
: randNum(0), fileStr("")
{
    dictionary["START"] = START;
    dictionary["EXIT"] = EXIT;
    dictionary["CORRIDOR"] = CORRIDOR;
    dictionary["FORK"] = FORK;
    dictionary["DEAD"] = DEAD;
    dictionary["NONE"] = NONE;
    
    directionDict[NORTH] = "north";
    directionDict[SOUTH] = "south";
    directionDict[EAST] = "east";
    directionDict[WEST] = "west";
    directionDict[NODIR] = "no direction";
    
}

// Deconstructor no memory management needed since no memory is allocated within this class
OtherFunctions::~OtherFunctions(){

}

// Random number generator takes two variables and randomly generates a number using the rand fuction
int OtherFunctions::getRandNum(int min, int max){
    time_t seed;
    seed = time(NULL) + oldseed;
    oldseed = seed;
    
    srand(uint(seed));
    
    int n = max - min + 1;
    int i = rand() % n;
    
    if(i < 0)
        i = -i;
    
    return min + i;
}

// File conversion to useable string format takes text file and converts to string closes file as required if found
string OtherFunctions::loadFile(string fileName){
    string line;
    fileStr = "";
    ifstream inFile (fileName);
    if (inFile.is_open()){
        while (getline(inFile, line)){
            fileStr +=line + "\n";
        }
        inFile.close();
    }else cout << "unable to open file";
    
    
    return fileStr;
}

// Returns a random direction from the direction enum
direction OtherFunctions::getRandDir(){
    randDir = getRandNum(0, 3);
    direction myDirection;
    switch (randDir){
        case 0:
            myDirection = NORTH;
            break;
        case 1:
            myDirection = EAST;
            break;
        case 2:
            myDirection = SOUTH;
            break;
        case 3:
            myDirection = WEST;
            break;
        default:
            myDirection = NODIR;
            break;
    }
    return myDirection;
}

// Converts a direction to a string using the direction map
string OtherFunctions::getStrFromRoomType(direction dirTStr){
    string dTFound;
    dTFound = directionDict.find(dirTStr)->second;
    return dTFound;
}

// Converts a string into a roomType using the roomtype map
roomType OtherFunctions::getRoomTypeFromString(string rTStr){
    roomType rTFound;
    rTFound = dictionary.find(rTStr)->second;
    return rTFound;
    
}

// Converts a string into a boolean value
bool OtherFunctions::getBoolFromString(string bStr){
    if (bStr == "true"){
        return true;
    }else {
        return false;
    }
}


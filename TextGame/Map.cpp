//
//  Map.cpp
//  TextGame
//
//  Created by Derek Critchfield on 5/4/16.
//  Copyright © 2016 Derek Critchfield. All rights reserved.
//

#include "Map.hpp"

/*
 * Map
 * Implementation
 */

/* Constructor sets the constant values for the row's and column's and the maximum attempts to find a path
 * through the room. Sets the attemptCount to 0 as well as creates the neccesary pointers to room objects for
 * each row and column and places them within level array. Calls functions to load the Room, Enemy, and Item
 * vectors.*/
Map::Map()
: ROW(10),
  COLUMN(30),
  ATTEMPTMAX(2000),
  attemptCount(0)
{
    level = new Room*[ROW];
    
    for (int i = 0; i < ROW; ++i){
        level[i] = new Room[COLUMN];
    }
    loadRooms();
    loadEnemies();
    loadItems();
}

// Deconstructor deallocates the memory in the array going through each cell then sets its value to zero to
// clear the array.
Map::~Map(){
    for (int i = 0; i < ROW; ++i){
        delete[] level[i];
        level[i] = 0;
    }
    delete[] level;
    level = 0;
}

void Map::resetLevel(){
    for (int i = 0; i < ROW; ++i){
        delete[] level[i];
        level[i] = 0;
    }
    delete[] level;
    level = 0;
    
    level = new Room*[ROW];
    
    for (int i = 0; i < ROW; ++i)
        level[i] = new Room[COLUMN];
    
    attemptCount = 0;
    generateLevel();
}

// Loads the Rooms.txt file and sends a istringstream for processing within the Room class till it reaches
// the end of the file.
void Map::loadRooms(){
    
    string garbage = "";
    
    istringstream stream (myFunctions.loadFile("Rooms.txt"));
    stream >> garbage >> numRooms;
    lRooms.reserve(numRooms);
    
    while (!stream.eof()){
        newRoom.loadRoom(stream);
        lRooms.push_back(newRoom);
    }
}

// Loads the Enemies.txt file and sends a istringstream for processing within the Enemy class till it reaches
// the end of the file.
void Map::loadEnemies(){
    
    string garbage = "";
    istringstream stream (myFunctions.loadFile("Enemies.txt"));
    stream >> garbage >> numEnemies;
    lEnemies.reserve(numEnemies);
    
    while (!stream.eof()){
        newEnemy.loadEnemy(stream);
        lEnemies.push_back(newEnemy);
    }
}

// Loads the Items.txt file and sends a istringstream for processing within the Item class till it reaches
// the end of the file.
void Map::loadItems(){
    
    string garbage = "";
    istringstream stream (myFunctions.loadFile("Items.txt"));
    stream >> garbage >> numItems;
    lItems.reserve(numItems);
    
    while (!stream.eof()){
        newItem.loadItem(stream);
        lItems.push_back(newItem);
    }
}

// Generates the exit rooms and finds a path from the starting room to the exit
void Map::setPath(){
    direction randDir;
    Room* newRoomPtr;
    
    // Loop that continues until the exit room is found
    while (roomPtr->getRType() != EXIT){
        
        // Increments the attempts to find the exit
        attemptCount++;
        
        // Checks if the attemptCount has reached the maximum number of attempts and resets the level if
        // necessary then breaking out of the loop
        if (attemptCount > ATTEMPTMAX){
            resetLevel();
            break;
        }
        
        // Checking for the number of exits from a room and storing possibile exits in the room exit room and
        // direction values and moving the pointer to the new room.
        if (roomPtr->getNumberExits() > 0){
            if (roomPtr->getExitDirection1() == NODIR){
                randDir = myFunctions.getRandDir();
                switch (randDir){
                    case NORTH:
                        if (roomPtr->getRoomCordX() -1 >= 0 && roomPtr->getEnterDirection() != SOUTH){
                            newRoomPtr =&level[roomPtr->getRoomCordX() -1][roomPtr->getRoomCordY()];
                            roomPtr->setExitDirection1(NORTH);
                            roomPtr->setExitRoom1(newRoomPtr);
                            newRoomPtr->setEnterRoom(roomPtr);
                            newRoomPtr->setEnterDirection(SOUTH);
                            roomPtr = newRoomPtr;
                        }
                        break;
                    
                    case SOUTH:
                        if (roomPtr->getRoomCordX() +1 < ROW && roomPtr->getEnterDirection() != NORTH){
                            newRoomPtr =&level[roomPtr->getRoomCordX() +1][roomPtr->getRoomCordY()];
                            roomPtr->setExitDirection1(SOUTH);
                            roomPtr->setExitRoom1(newRoomPtr);
                            newRoomPtr->setEnterRoom(roomPtr);
                            newRoomPtr->setEnterDirection(NORTH);
                            roomPtr = newRoomPtr;
                        }
                        break;
                    
                    case EAST:
                        if (roomPtr->getRoomCordY() +1 < COLUMN && roomPtr->getEnterDirection() != WEST){
                            newRoomPtr =&level[roomPtr->getRoomCordX()][roomPtr->getRoomCordY() +1];
                            roomPtr->setExitDirection1(EAST);
                            roomPtr->setExitRoom1(newRoomPtr);
                            newRoomPtr->setEnterRoom(roomPtr);
                            newRoomPtr->setEnterDirection(WEST);
                            roomPtr = newRoomPtr;
                        }
                        break;
                    
                    default:
                        if (roomPtr->getRoomCordY() -1 >= 0 && roomPtr->getEnterDirection() != EAST){
                            newRoomPtr =&level[roomPtr->getRoomCordX()][roomPtr->getRoomCordY() -1];
                            roomPtr->setExitDirection1(WEST);
                            roomPtr->setExitRoom1(newRoomPtr);
                            newRoomPtr->setEnterRoom(roomPtr);
                            newRoomPtr->setEnterDirection(EAST);
                            roomPtr = newRoomPtr;
                        }
                        break;
                }
            }else if (roomPtr->getExitDirection2() == NODIR && roomPtr->getNumberExits() > 1){
                randDir = myFunctions.getRandDir();
                switch (randDir){
                    case NORTH:
                        if (roomPtr->getRoomCordX() -1 >= 0 && roomPtr->getEnterDirection() != SOUTH){
                            newRoomPtr =&level[roomPtr->getRoomCordX() -1][roomPtr->getRoomCordY()];
                            roomPtr->setExitDirection2(NORTH);
                            roomPtr->setExitRoom2(newRoomPtr);
                            newRoomPtr->setEnterRoom(roomPtr);
                            newRoomPtr->setEnterDirection(SOUTH);
                            roomPtr = newRoomPtr;
                        }
                        break;
                        
                    case SOUTH:
                        if (roomPtr->getRoomCordX() +1 < ROW && roomPtr->getEnterDirection() != NORTH){
                            newRoomPtr =&level[roomPtr->getRoomCordX() +1][roomPtr->getRoomCordY()];
                            roomPtr->setExitDirection2(SOUTH);
                            roomPtr->setExitRoom2(newRoomPtr);
                            newRoomPtr->setEnterRoom(roomPtr);
                            newRoomPtr->setEnterDirection(NORTH);
                            roomPtr = newRoomPtr;
                        }
                        break;
                        
                    case EAST:
                        if (roomPtr->getRoomCordY() +1 < COLUMN && roomPtr->getEnterDirection() != WEST){
                            newRoomPtr =&level[roomPtr->getRoomCordX()][roomPtr->getRoomCordY() +1];
                            roomPtr->setExitDirection2(EAST);
                            roomPtr->setExitRoom1(newRoomPtr);
                            newRoomPtr->setEnterRoom(roomPtr);
                            newRoomPtr->setEnterDirection(WEST);
                            roomPtr = newRoomPtr;
                        }
                        break;
                        
                    default:
                        if (roomPtr->getRoomCordY() -1 >= 0 && roomPtr->getEnterDirection() != EAST){
                            newRoomPtr =&level[roomPtr->getRoomCordX()][roomPtr->getRoomCordY() -1];
                            roomPtr->setExitDirection2(WEST);
                            roomPtr->setExitRoom2(newRoomPtr);
                            newRoomPtr->setEnterRoom(roomPtr);
                            newRoomPtr->setEnterDirection(EAST);
                            roomPtr = newRoomPtr;
                        }
                        break;
                }
            }else if (roomPtr->getExitDirection3() == NODIR && roomPtr->getNumberExits() > 2){
                randDir = myFunctions.getRandDir();
                switch (randDir){
                    case NORTH:
                        if (roomPtr->getRoomCordX() -1 >= 0 && roomPtr->getEnterDirection() != SOUTH){
                            newRoomPtr =&level[roomPtr->getRoomCordX() -1][roomPtr->getRoomCordY()];
                            roomPtr->setExitDirection3(NORTH);
                            roomPtr->setExitRoom3(newRoomPtr);
                            newRoomPtr->setEnterRoom(roomPtr);
                            newRoomPtr->setEnterDirection(SOUTH);
                            roomPtr = newRoomPtr;
                        }
                        break;
                        
                    case SOUTH:
                        if (roomPtr->getRoomCordX() +1 < ROW && roomPtr->getEnterDirection() != NORTH){
                            newRoomPtr =&level[roomPtr->getRoomCordX() +1][roomPtr->getRoomCordY()];
                            roomPtr->setExitDirection3(SOUTH);
                            roomPtr->setExitRoom3(newRoomPtr);
                            newRoomPtr->setEnterRoom(roomPtr);
                            newRoomPtr->setEnterDirection(NORTH);
                            roomPtr = newRoomPtr;
                        }
                        break;
                        
                    case EAST:
                        if (roomPtr->getRoomCordY() +1 < COLUMN && roomPtr->getEnterDirection() != WEST){
                            newRoomPtr =&level[roomPtr->getRoomCordX()][roomPtr->getRoomCordY() +1];
                            roomPtr->setExitDirection3(EAST);
                            roomPtr->setExitRoom3(newRoomPtr);
                            newRoomPtr->setEnterRoom(roomPtr);
                            newRoomPtr->setEnterDirection(WEST);
                            roomPtr = newRoomPtr;
                        }
                        break;
                        
                    default:
                        if (roomPtr->getRoomCordY() -1 >= 0 && roomPtr->getEnterDirection() != EAST){
                            newRoomPtr =&level[roomPtr->getRoomCordX()][roomPtr->getRoomCordY() -1];
                            roomPtr->setExitDirection3(WEST);
                            roomPtr->setExitRoom3(newRoomPtr);
                            newRoomPtr->setEnterRoom(roomPtr);
                            newRoomPtr->setEnterDirection(EAST);
                            roomPtr = newRoomPtr;
                        }
                        break;
                }
            }else{
                // Clears the exit direction for each possible exit
                roomPtr->setExitDirection1(NODIR);
                roomPtr->setExitDirection2(NODIR);
                roomPtr->setExitDirection3(NODIR);
                
            }
        }else{
            // Steps the room pointer to the previous room if no exit was found or if exceeding the
            // number of possible exits
            roomPtr = roomPtr->getEnterRoom();
        }
    }
}

// Generates the rooms for each cell in the array with a start and end location as well as calls the set path
// function for the player to walk through additional details in the function.
void Map::generateLevel(){
    
    int randRoom;
    int randEnemies;
    int randItems;
    int startX, startY;
    int exitX, exitY;
    
    //set startroom location
    startX = myFunctions.getRandNum(0, ROW -1);
    startY = myFunctions.getRandNum(0, COLUMN -1);
    level[startX][startY] =lRooms[0];
    level[startX][startY].setRoomCordX(startX);
    level[startX][startY].setRoomCordY(startY);
    
    //set roomPtr to startroom
    roomPtr = &level[startX][startY];
    
    //set exitroom location
    do {
        exitX = myFunctions.getRandNum(0, ROW -1);
        exitY = myFunctions.getRandNum(0, COLUMN -1);
        if (level[exitX][exitY].getRType() == NONE){
            level[exitX][exitY] =lRooms[1];
            level[exitX][exitY].setRoomCordX(exitX);
            level[exitX][exitY].setRoomCordY(exitY);
        }
    }while(level[exitX][exitY].getRType() != EXIT);
    
    //set roomtype for rest of rooms in level
    for (int x = 0; x < ROW; x++){
        for (int y = 0; y < COLUMN; y++){
            if (level[x][y].getRType() == NONE){
                randRoom = myFunctions.getRandNum(3, numRooms) -1;
                randEnemies = myFunctions.getRandNum(0, 4);
                randItems = myFunctions. getRandNum(0, 1);
                level[x][y] = lRooms[randRoom];
                level[x][y].setRoomCordX(x);
                level[x][y].setRoomCordY(y);
                level[x][y].setNumberEnemies(randEnemies);
                level[x][y].setNumberItems(randItems);
            }
        }
    }
    //generate a path through level
    setPath();
    
    //set roomPtr back to startroom
    for (int x = 0; x < ROW; x++){
        for (int y = 0; y < COLUMN; y++){
            if (level[x][y].getRType() == START){
                roomPtr = &level[x][y];
            }
        }
    }
}

// Displays path taken through each room with an space filling each room that has not been visited
void Map::printLevel(){
    for (int x = 0; x < ROW; x++){
        
        for (int y = 0; y < COLUMN; y++){
            if (level[x][y].getHasBeenEntered()) {
                cout << "X";
            }else{
                cout << " ";
            }
            cout << " ";
        }
        cout << endl;
    }    
}

// getters and setters
Room* Map::getRoomPtr(){
    return roomPtr;
}

void Map::setRoomPtr(Room* currRoom){
    roomPtr = currRoom;
}

vector<Enemy> Map::getlEnemies(){
    return lEnemies;
}

vector<Item> Map::getlItems(){
    return lItems;
}
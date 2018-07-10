//
//  Room.cpp
//  TextGame
//
//  Created by Derek Critchfield on 5/4/16.
//  Copyright © 2016 Derek Critchfield. All rights reserved.
//

#include "Room.hpp"

/*
 * Room
 * Implementation
 */

// Constructor sets all attributes to empty and hasBeenEntered to false
Room::Room()
:name("NO NAME"),
 enterRoom(nullptr),
 exitRoom1(nullptr),
 exitRoom2(nullptr),
 exitRoom3(nullptr),
 numberItems(0),
 numberEnemies(0),
 enterDirection(NODIR),
 exitDirection1(NODIR),
 exitDirection2(NODIR),
 exitDirection3(NODIR),
 numberExits(0),
 rType(NONE),
 hasBeenEntered(false)
{
    
}

// Deconstructor no memory management needed since no memory is allocated within this class
Room::~Room(){
    
}


// Loads Rooms from a formatted string stream setting necessary attributes
void Room::loadRoom(istringstream& stream){
    string garbage = "";
    string rTStr;
    stream >> garbage;
    stream >> ws;
    getline(stream, name);
    stream >> garbage;
    stream >> ws;
    getline(stream, description);
    stream >> garbage >> numberExits;
    stream >> garbage;
    stream >> ws;
    getline(stream, rTStr);
    rType = myOtherFunc.getRoomTypeFromString(rTStr);
    stream >> ws;
}

// getters and setters
string Room::getName(){
    return name;
}

void Room::setName(string nName){
    name = nName;
}

string Room::getDescription(){
    return description;
}

void Room::setDescription(string nDes){
    description = nDes;
}

Room* Room::getEnterRoom(){
    return enterRoom;
}

void Room::setEnterRoom(Room* nER){
    enterRoom = nER;
}

Room* Room::getExitRoom1(){
    return exitRoom1;
}

void Room::setExitRoom1(Room* nER1){
    exitRoom1 = nER1;
}

Room* Room::getExitRoom2(){
    return exitRoom2;
}

void Room::setExitRoom2(Room* nER2){
    exitRoom2 = nER2;
}

Room* Room::getExitRoom3(){
    return exitRoom3;
}

void Room::setExitRoom3(Room* nER3){
    exitRoom3 = nER3;
}

string Room::getItemsContained(){
    return itemsContained;
}

void Room::setItemsContained(string nIC){
    itemsContained = nIC;
}

string Room::getEnemiesContained(){
    return enemiesContained;
}

void Room::setEnemiesContained(string nEC){
    enemiesContained = nEC;
}

int Room::getNumberItems(){
    return numberItems;
}

void Room::setNumberItems(int nIt){
    numberItems = nIt;
}

int Room::getNumberEnemies(){
    return numberEnemies;
}

void Room::setNumberEnemies(int nEn){
    numberEnemies = nEn;
}

direction Room::getEnterDirection(){
    return enterDirection;
}

void Room::setEnterDirection(direction nED){
    enterDirection = nED;
}

direction Room::getExitDirection1(){
    return exitDirection1;
}

void Room::setExitDirection1(direction nXD1){
    exitDirection1 = nXD1;
}

direction Room::getExitDirection2(){
    return exitDirection2;
}

void Room::setExitDirection2(direction nXD2){
    exitDirection2 = nXD2;
}

direction Room::getExitDirection3(){
    return exitDirection3;
}

void Room::setExitDirection3(direction nXD3){
    exitDirection3 =nXD3;
}

int Room::getNumberExits(){
    return numberExits;
}

void Room::setNumberExits(int nEx){
    numberExits = nEx;
}

roomType Room::getRType(){
    return rType;
}

void Room::setRType(roomType nRT){
    rType = nRT;
}

int Room::getRoomCordX(){
    return roomCordX;
}

void Room::setRoomCordX(int nRCX){
    roomCordX = nRCX;
}

int Room::getRoomCordY(){
    return roomCordY;
}

void Room::setRoomCordY(int nRCY){
    roomCordY = nRCY;
}

bool Room::getHasBeenEntered(){
    return hasBeenEntered;
}

void Room::setHasBeenEntered(bool nHBE){
    hasBeenEntered = nHBE;
}

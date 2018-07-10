//
//  GameManager.cpp
//  TextGame
//
//  Created by Derek Critchfield on 5/4/16.
//  Copyright © 2016 Derek Critchfield. All rights reserved.
//

#include "GameManager.hpp"

/*
 * GameManager
 * Implementation
 */

// Constructor sets initial value for the randEnemyType and the randItemType to -1.
GameManager::GameManager()
:randEnemyType(-1),
 randItemType(-1)
{

}

// Deconstructor no memory management needed since no memory is allocated within this class
GameManager::~GameManager(){

}

// Function which handles the main game loop takes a Player object which is used within the function.
bool GameManager::playGame(Player currPlayer){
    
    // Generation of Level through the Map's generate Level function.
    myMap.generateLevel();
    
    // Welcome statement as well as requestiong the users name up to 16 chars long
    cout << "Welcome to the Endless Dungeon!!" << endl;
    cout << "What shall I call you adventurer(16 character maximum): ";
    
    // Reads console input using the CinReader readString Function
    userInput = reader.readString(false, 16);
    currPlayer.setName(userInput);
  
    // Main Game Loop stats here will continue until the player quits or has died.
    do {
        
        // Checks if the player has entered and new room and if so clears the rooms item vector and resets randItemType to -1.
        if (lastRoom != myMap.getRoomPtr()){
            currItem.clear();
            randItemType = -1;
        }
        
        // Checks if user has typed in the look command or if the player has entered new room. If true then displays room info.
        if (lastRoom != myMap.getRoomPtr() || userInput == "LOOK"){
            cout << endl;
            myMap.getRoomPtr()->setHasBeenEntered(true);
            numOfStars = int(myMap.getRoomPtr()->getName().length() +4);
            for (int i = 0; i < numOfStars; i++){
                cout << "*";
            }
            cout << endl;
            cout << "* " << myMap.getRoomPtr()->getName() << " *" << endl;
            for (int i = 0; i < numOfStars; i++){
                cout << "*";
            }
            cout << endl;
            cout << myMap.getRoomPtr()->getDescription() << endl;
        
            
            //Gives info about the available exits from the current room part of the room info
            if (myMap.getRoomPtr()->getExitDirection1() != NODIR){
                cout << "You can go " << myOtherFunc.getStrFromRoomType(myMap.getRoomPtr()->getExitDirection1());
            }
            if (myMap.getRoomPtr()->getExitDirection2() != NODIR && myMap.getRoomPtr()->getExitDirection2() != myMap.getRoomPtr()->getExitDirection1()){
                cout << " and you can go " << myOtherFunc.getStrFromRoomType(myMap.getRoomPtr()->getExitDirection2());
            }
            if (myMap.getRoomPtr()->getExitDirection3() != NODIR && myMap.getRoomPtr()->getExitDirection3() != myMap.getRoomPtr()->getExitDirection1() && myMap.getRoomPtr()->getExitDirection3() != myMap.getRoomPtr()->getExitDirection2()){
                cout << " and you can go " << myOtherFunc.getStrFromRoomType(myMap.getRoomPtr()->getExitDirection3());
            }
        
            if (myMap.getRoomPtr()->getExitDirection1() != NODIR){
                cout << "." << endl;
            }
        }
        
        // Checks the room for enemies
        if (myMap.getRoomPtr()->getNumberEnemies() > 0){
            
            // if the room contains enemies that have not been previously selected select them now and load them
            // into the currEnemy vector.
            if (randEnemyType == -1){
                randEnemyType = myOtherFunc.getRandNum(0, int(myMap.getlEnemies().size())-1);
                for (int i = 0; i < myMap.getRoomPtr()->getNumberEnemies(); i++ ){
                    currEnemy.push_back(myMap.getlEnemies()[randEnemyType]);
                }
            }
            // Displays the enemy types and quantity in the current room.
            cout << endl;
            cout << "There is " << myMap.getRoomPtr()->getNumberEnemies() << " ";
            cout << myMap.getlEnemies()[randEnemyType].getName() << "(s) in this room." << endl;
        }
        
        // Checks the room for items
        if (myMap.getRoomPtr()->getNumberItems() > 0){
            // if the room contains items that have not been previously selected select them now and load them
            // into the currItem vector.
            if (randItemType == -1){
                randItemType = myOtherFunc.getRandNum(0, int(myMap.getlItems().size())-1);
                for (int i = 0; i < myMap.getRoomPtr()->getNumberItems(); i++ ){
                    currItem.push_back(myMap.getlItems()[randItemType]);
                }
            }
            // Displays the items within the room.
            for (int i = 0; i < currItem.size(); i++){
                cout << endl;
                cout << "There is a " << currItem[i].getName() << " in this room." << endl;
            }
        }
        
        // promps user for a list of commands and sets the lastRoom pointer to the current room
        lastRoom = myMap.getRoomPtr();
        cout << endl;
        cout << "What would you like to do(Type help for a list of options): ";
        userInput = reader.readString(false, 0);
        // Capitalizes user input to more effectively manage thoughout the options screen
        transform (userInput.begin(), userInput.end(), userInput.begin(), [](unsigned char c) {return toupper(c);});
        
        // Calls the printLevel function if the user inputs the show map command
        if (userInput == "SHOW MAP"){
            myMap.printLevel();
        
        }
        
        // Calls the describe function on the player if the user inputs the describe command
        if (userInput == "STATS"){
            currPlayer.describe();
        }
        
        // Checks for the go north command and checks each exit direction and the enterance direction for paths
        // if there is an exit path moves the room pointer to that room
        if (userInput == "GO NORTH"){
            if (myMap.getRoomPtr()->getNumberEnemies() > 0){
                cout << endl;
                cout << "A " << myMap.getlEnemies()[randEnemyType].getName() << " blocks your path." << endl;
            }else if (myMap.getRoomPtr()->getExitDirection1() == NORTH){
                myMap.setRoomPtr(myMap.getRoomPtr()->getExitRoom1());
            }else if (myMap.getRoomPtr()->getExitDirection2() == NORTH){
                myMap.setRoomPtr(myMap.getRoomPtr()->getExitRoom2());
            }else if (myMap.getRoomPtr()->getExitDirection3() == NORTH){
                myMap.setRoomPtr(myMap.getRoomPtr()->getExitRoom3());
            }else if (myMap.getRoomPtr()->getEnterDirection() == NORTH){
                myMap.setRoomPtr(myMap.getRoomPtr()->getEnterRoom());
            }else {
                cout << endl;
                cout << "You cannot go that direction." << endl;
            }
            
        }
        
        // Checks for the go south command and checks each exit direction and the enterance direction for paths
        // if there is an exit path moves the room pointer to that room
        if (userInput == "GO SOUTH"){
            if (myMap.getRoomPtr()->getNumberEnemies() > 0){
                cout << endl;
                cout << "A " << myMap.getlEnemies()[randEnemyType].getName() << " blocks your path." << endl;
            }else if (myMap.getRoomPtr()->getExitDirection1() == SOUTH){
                myMap.setRoomPtr(myMap.getRoomPtr()->getExitRoom1());
            }else if (myMap.getRoomPtr()->getExitDirection2() == SOUTH){
                myMap.setRoomPtr(myMap.getRoomPtr()->getExitRoom2());
            }else if (myMap.getRoomPtr()->getExitDirection3() == SOUTH){
                myMap.setRoomPtr(myMap.getRoomPtr()->getExitRoom3());
            }else if (myMap.getRoomPtr()->getEnterDirection() == SOUTH){
                myMap.setRoomPtr(myMap.getRoomPtr()->getEnterRoom());
            }else {
                cout << endl;
                cout << "You cannot go that direction." << endl;
            }
            
        }
        
        // Checks for the go east command and checks each exit direction and the enterance direction for paths
        // if there is an exit path moves the room pointer to that room
        if (userInput == "GO EAST"){
            if (myMap.getRoomPtr()->getNumberEnemies() > 0){
                cout << endl;
                cout << "A " << myMap.getlEnemies()[randEnemyType].getName() << " blocks your path." << endl;
            }else if (myMap.getRoomPtr()->getExitDirection1() == EAST){
                myMap.setRoomPtr(myMap.getRoomPtr()->getExitRoom1());
            }else if (myMap.getRoomPtr()->getExitDirection2() == EAST){
                myMap.setRoomPtr(myMap.getRoomPtr()->getExitRoom2());
            }else if (myMap.getRoomPtr()->getExitDirection3() == EAST){
                myMap.setRoomPtr(myMap.getRoomPtr()->getExitRoom3());
            }else if (myMap.getRoomPtr()->getEnterDirection() == EAST){
                myMap.setRoomPtr(myMap.getRoomPtr()->getEnterRoom());
            }else {
                cout << endl;
                cout << "You cannot go that direction." << endl;
            }
            
        }
        
        // Checks for the go west command and checks each exit direction and the enterance direction for paths
        // if there is an exit path moves the room pointer to that room
        if (userInput == "GO WEST"){
            if (myMap.getRoomPtr()->getNumberEnemies() > 0){
                cout << endl;
                cout << "A " << myMap.getlEnemies()[randEnemyType].getName() << " blocks your path." << endl;
            }else if (myMap.getRoomPtr()->getExitDirection1() == WEST){
                myMap.setRoomPtr(myMap.getRoomPtr()->getExitRoom1());
            }else if (myMap.getRoomPtr()->getExitDirection2() == WEST){
                myMap.setRoomPtr(myMap.getRoomPtr()->getExitRoom2());
            }else if (myMap.getRoomPtr()->getExitDirection3() == WEST){
                myMap.setRoomPtr(myMap.getRoomPtr()->getExitRoom3());
            }else if (myMap.getRoomPtr()->getEnterDirection() == WEST){
                myMap.setRoomPtr(myMap.getRoomPtr()->getEnterRoom());
            }else {
                cout << endl;
                cout << "You cannot go that direction." << endl;
            }
            
        }
        
        // Checks for the go down command and resets the Map using the resetLevel function
        if (userInput == "GO DOWN"){
            if (myMap.getRoomPtr()->getRType() == EXIT){
                myMap.resetLevel();
            }else {
                cout << endl;
                cout << "There are no stairs here!" << endl;
            }
        }
        
        // Checks for the attack command and checks for an enemy to attack
        if (userInput == "ATTACK"){
            if (currEnemy.size() > 0){
                
                // calculates random attacks and blocks for the player based on stats
                int randPlAtkAmt = myOtherFunc.getRandNum(0, currPlayer.getAttack());
                int randPlBlkAmt = myOtherFunc.getRandNum(0, currPlayer.getBlock());
                int randEnAtkAmt = myOtherFunc.getRandNum(0, currEnemy[0].getAttack());
                int randEnBlkAmt = myOtherFunc.getRandNum(0, currEnemy[0].getBlock());
                
                // calculates the player and enemy damage
                int plDamage = (randPlAtkAmt - ((randPlAtkAmt * currEnemy[0].getArmor()) /100)) - randEnBlkAmt;
                int enDamage = (randEnAtkAmt - ((randEnAtkAmt * currPlayer.getArmor()) /100)) - randPlBlkAmt;
                
                // notifys user of result of players attack and adjusts enemies health accordingly
                cout << endl;
                cout << "You attack the closest " << currEnemy[0].getName() << "." << endl;
                if (plDamage <= 0){
                    cout << "You missed!" << endl;
                }else {
                    currEnemy[0].setHealth(currEnemy[0].getHealth() - plDamage);
                    cout << "You did " << plDamage << " damage!" << endl;
                }
                
                // checks whether or not the players attack has killed the enemy
                if (currEnemy[0].getHealth() <= 0){
                    currEnemy[0].setIsAlive(false);
                    cout << "The " << currEnemy[0].getName() << " has been defeated!" << endl;
                }else {
                    // if the player has not killed the enemy check for the enemies attack and adjust players health accordingly
                    cout << "The " << currEnemy[0].getName() << " attacks";
                    if (enDamage > 0){
                        currPlayer.setHealth(currPlayer.getHealth() - enDamage);
                        cout << " and does " << enDamage << " damage to you!" << endl;
                    }else {
                        cout << " and misses!" << endl;
                    }
                }
                
                // erases enemy if the enemy has dies and resets the randEnemyType to -1
                if (currEnemy[0].getIsAlive() == false){
                    currEnemy.erase(currEnemy.begin());
                    myMap.getRoomPtr()->setNumberEnemies(myMap.getRoomPtr()->getNumberEnemies() - 1);
                }
                if (myMap.getRoomPtr()->getNumberEnemies() == 0){
                    randEnemyType = -1;
                }
            }else {
                // prompts user that there is no enemies to attack if the result of the initial check returns false
                cout << endl;
                cout << "There is nothing to attack." << endl;
            }
        }
        
        // checks user input for the pickup item command and whether or not the player can carry the item
        if (!currItem.empty()){
            if (userInput == "GET " + currItem[0].getName()){
                if (currPlayer.addItemToInventory(currItem[0])){
                    //removes te item from the ground if it has been added to the players inventory
                    currItem.erase(currItem.begin());
                    myMap.getRoomPtr()->setNumberItems(myMap.getRoomPtr()->getNumberItems()-1);
                }else {
                    cout << endl;
                    cout << "Your inventory is full!" << endl;
                }
            }
        }
        
        // checks user input for the drop command and if necesary adds it to the current room
        if (!currPlayer.getInventoryVector()->empty()){
            for (int x = 0; x < currPlayer.getInventoryVector()->size(); x++){
                if (userInput == "DROP " + currPlayer.getInventoryVector()->at(x).getName()){
                    if (!currPlayer.getInventoryVector()->at(x).getIsEquipped()){
                        currItem.push_back(currPlayer.getInventoryVector()->at(x));
                        currPlayer.getInventoryVector()->erase(currPlayer.getInventoryVector()->begin() + x);
                        myMap.getRoomPtr()->setNumberItems(myMap.getRoomPtr()->getNumberItems()+1);
                    }
                // checks if the player is attemting to drop an equiped item
                }else if (userInput + "(E)" == "DROP " + currPlayer.getInventoryVector()->at(x).getName()){
                    cout << endl;
                    cout << "You must unequip that item before you can drop it!" << endl;
                }
            }
        }
        
        // checks user input for the equip command and adjusts player attributes as needed if the item can be equipped
        if (!currPlayer.getInventoryVector()->empty()){
            for (int x = 0; x < currPlayer.getInventoryVector()->size(); x++){
                if (userInput == "EQUIP " + currPlayer.getInventoryVector()->at(x).getName()){
                    if (currPlayer.getInventoryVector()->at(x).getIsEquipable()){
                        cout << endl;
                        cout << "Your " << currPlayer.getInventoryVector()->at(x).getName() << " is now equipped." << endl;
                        currPlayer.getInventoryVector()->at(x).setIsEquipped(true);
                        currPlayer.setHealth(currPlayer.getHealth() + currPlayer.getInventoryVector()->at(x).getHealthAdd());
                        currPlayer.setArmor(currPlayer.getArmor() + currPlayer.getInventoryVector()->at(x).getArmorAdd());
                        currPlayer.setBlock(currPlayer.getBlock() + currPlayer.getInventoryVector()->at(x).getBlockAdd());
                        currPlayer.setAttack(currPlayer.getAttack() + currPlayer.getInventoryVector()->at(x).getAttackAdd());
                
                        
                    }else {
                        cout << endl;
                        cout << "You cannot equip that!!" << endl;
                    }
                }
            }
        }

        // Checks user input for the unequip command and adjusts the necessary attribues
        if (!currPlayer.getInventoryVector()->empty()){
            for (int x = 0; x < currPlayer.getInventoryVector()->size(); x++){
                if (userInput + "(E)" == "UNEQUIP " + currPlayer.getInventoryVector()->at(x).getName()){
                    if (currPlayer.getInventoryVector()->at(x).getIsEquipped()){
                        currPlayer.getInventoryVector()->at(x).setIsEquipped(false);
                        cout << endl;
                        cout << "Your " << currPlayer.getInventoryVector()->at(x).getName() << " is now unequipped." << endl;
                        currPlayer.setHealth(currPlayer.getHealth() - currPlayer.getInventoryVector()->at(x).getHealthAdd());
                        currPlayer.setArmor(currPlayer.getArmor() - currPlayer.getInventoryVector()->at(x).getArmorAdd());
                        currPlayer.setBlock(currPlayer.getBlock() - currPlayer.getInventoryVector()->at(x).getBlockAdd());
                        currPlayer.setAttack(currPlayer.getAttack() - currPlayer.getInventoryVector()->at(x).getAttackAdd());
                        
                    // If the user attempts to unequip an item that cannot be unequipped prompts user
                    }else {
                        cout << endl;
                        cout << "You cannot unequip that!!" << endl;
                    }
                }
            }
        }
        
        // Checks user input for the use item command and adjusts attributes according
        if (!currPlayer.getInventoryVector()->empty()){
            for (int x = 0; x < currPlayer.getInventoryVector()->size(); x++){
                if (userInput == "USE " + currPlayer.getInventoryVector()->at(x).getName()){
                    if (currPlayer.getInventoryVector()->at(x).getIsUseable()){
                        currPlayer.getInventoryVector()->at(x).setIsUsed(true);
                        cout << endl;
                        cout << "You have used your " << currPlayer.getInventoryVector()->at(x).getName() << "." << endl;
                        currPlayer.setHealth(currPlayer.getHealth() + currPlayer.getInventoryVector()->at(x).getHealthAdd());
                        currPlayer.setArmor(currPlayer.getArmor() + currPlayer.getInventoryVector()->at(x).getArmorAdd());
                        currPlayer.setBlock(currPlayer.getBlock() + currPlayer.getInventoryVector()->at(x).getBlockAdd());
                        currPlayer.setAttack(currPlayer.getAttack() + currPlayer.getInventoryVector()->at(x).getAttackAdd());
                        currPlayer.getInventoryVector()->erase(currPlayer.getInventoryVector()->begin() + x);
                        
                    // Informs user of failed attempt to use an item
                    }else {
                        cout << endl;
                        cout << "You cannot use that!!" << endl;
                    }
                }
            }
        }

        // Checks user input for the help command if entered lists possible commands that can be given
        if (userInput == "HELP"){
            cout << "Type look to get the see the name and description of the current room." << endl;
            cout << "Type get and the name of an object to add it to your inventory." << endl;
            cout << "Type drop and the name of an object to remove it from your inventory." << endl;
            cout << "Type equip and the name of an item to equip it." << endl;
            cout << "Type unequip and the name of an item to unequip it." << endl;
            cout << "Type use and the name of the item to use item." << endl;
            cout << "Type show map for a map of the current level." << endl;
            cout << "Type stats to show your current stats." << endl;
            cout << "Type go north, south, east, or west to go to the next room." << endl;
            cout << "Type go down to climb down a staircase to next level." << endl;
            cout << "Type attack to attack any monsters in the room." << endl;
            cout << "Type quit or q to quit the game." << endl;
        }
        
        // Checks if the player has died and sets isAlive to false if health has reached zero
        if (currPlayer.getHealth() <= 0){
            currPlayer.setIsAlive(false);
        }
        
        // Checks if player is alive and gives option to play again returning true to the main function loop
        // Or changes the user input to Q so that it ends the main function loop
        if (currPlayer.getIsAlive() == false){
            cout << endl;
            cout << "You have died!!" << endl;
            do{
                cout << "Would you like to play again(Type Y for yes or N for no): " ;
                userInput = reader.readString(false, 0);
                transform (userInput.begin(), userInput.end(), userInput.begin(), [](unsigned char c) {return std::toupper(c);});
                if (userInput == "N" || userInput == "NO"){
                    userInput = "Q";
                }else if (userInput == "Y" || userInput == "YES"){
                    cout << endl;
                    return true;
                }
            }while (userInput != "Q");
        }
    }while(userInput != "QUIT" && userInput != "Q");
    return false;
}
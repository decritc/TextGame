//
//  Enemy.cpp
//  TextGame
//
//  Created by Derek Critchfield on 5/4/16.
//  Copyright © 2016 Derek Critchfield. All rights reserved.
//

#include "Enemy.hpp"

/*
 * Enemy
 * Implementation
 */

//Constructor
Enemy::Enemy()
{

}

// Deconstructor no memory management needed since no memory is allocated within this class
Enemy::~Enemy(){

}

// Loads Enemys from a formatted string stream setting necessary attributes 
void Enemy::loadEnemy(istringstream& stream){
    string garbage = "";
    string tempName = "";
    int tempStat;
    bool tempIsAlive;
    
    stream >> garbage;
    stream >> ws;
    getline(stream, tempName);
    setName(tempName);
    stream >> garbage >> tempStat;
    setHealth(tempStat);
    stream >> garbage >> ws >> tempIsAlive;
    setIsAlive(tempIsAlive);
    stream >> garbage >> tempStat;
    setLevel(tempStat);
    stream >> garbage >> tempStat;
    setArmor(tempStat);
    stream >> garbage >> tempStat;
    setBlock(tempStat);
    stream >> garbage >> tempStat;
    setAttack(tempStat);
    stream >> ws;
}

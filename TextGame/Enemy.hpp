//
//  Enemy.hpp
//  TextGame
//
//  Created by Derek Critchfield on 5/4/16.
//  Copyright © 2016 Derek Critchfield. All rights reserved.
//

#ifndef Enemy_hpp
#define Enemy_hpp

#pragma once

#include <iostream>
#include <sstream>
#include "player.hpp"

using namespace std;

/*
 * Enemy
 * Derived from Player class includes function for constructing enemies from a string stream
 */

class Enemy:public Player {
private:
    
public:
    Enemy();
    ~Enemy();
    void loadEnemy(istringstream& stream);
};

#endif /* Enemy_hpp */

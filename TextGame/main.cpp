/*
 * The Endless Dungeon
 * A rougelike text adventure game with endless opportunity to battle monsters and collect usefull items
 * never ending design in mind for endless hours of old school gaming excitement.
 *
 * Derek Critchfield
 * Date created: 5/13/16
 */

#include <iostream>
#include "GameManager.hpp"


using namespace std;

int main(int argc, const char * argv[]) {
    
    // continueGame stores the boolean result from the main game loop that is trigered if player decided
    // to continue playing after death.
    bool continueGame;
    
    // Game loop that initiates initial gameManager and player and hands over operation to the main game loop.
    // Also handles creation of game objects and cleaning up the allocated memory through each pass.
    do{
        GameManager *currGame = new GameManager();
        Player *currPlayer = new Player();
        continueGame = currGame->playGame(*currPlayer);
        delete currPlayer;
        delete currGame;
    }while (continueGame);
    

    return 0;
}

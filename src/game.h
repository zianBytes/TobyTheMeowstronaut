/* This is the header file for the game structure and function prototypes.
 * The Function definition can be found in the implementation file called
 * game.cpp
 */

#ifndef GAME_H
#define GAME_H

#include "raylib.h"

// Adding HomePage
enum GameState {HOMEPAGE, PLAYING};

// struct Star {
//  Vector2 position;
//  float speed;
// };

class Game {
private:
 Texture2D background;
 GameState currentState = HOMEPAGE;
 //Score Board:
 int score = 0;
 //Adding Stars and Other materials to the homepage:


public:
 // Function prototype to store the game background.
 void Init();
 void Update();
 void Draw();
 void Cleanup();

 void IncreaseScore();

 GameState GetState() {
  return currentState;
 }
};


#endif //GAME_H

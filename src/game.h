/* This is the header file for the game structure and function prototypes.
 * The Function definition can be found in the implementation file called
 * game.cpp
 */

#ifndef GAME_H
#define GAME_H

#include "raylib.h"

// Adding HomePage
enum GameState {HOMEPAGE, PLAYING, PAUSED, YOUSUREVRO, GAMEOVER};

class Game {
private:
 Texture2D background;
 GameState currentState = HOMEPAGE;
 // Original Plan was to have a scoreboard. I'm replacing it with a real time timer.
 // Basically whoever can last longer in the game.
 float survivalTime = 0.0f;
 bool timerRunning = false;

public:
 // Function prototype to store the game background.
 void Init();
 void Update();
 void Draw();
 void Cleanup();
 void SetGameOver();
 void SetPlaying();
 void SetHomepage();

 GameState GetState();
 //
 float GetSurvivalTime();
 void SetPaused();
};



#endif //GAME_H

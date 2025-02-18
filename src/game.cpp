// Tobby The Meowstronaut
// Implementation file for function defitions.

#include "game.h"
#include <cmath>

void Game::Init() {
    // background = LoadTexture("assets/background.png");
    currentState = HOMEPAGE;
}
void Game::Update() {
    // Handle Game Logic
    if (currentState == HOMEPAGE) {
        if(IsKeyPressed(KEY_SPACE)) {
            currentState = PLAYING;
        }
    }
}

void Game::Draw() {
    // BeginDrawing();
    // ClearBackground((Color){25,25,112,255});

    //Glow Effect using sin() function.
    //This is where cMath is needed.

    float glowAlpha = (sin(GetTime()*4)+1)/2;

    if(currentState == HOMEPAGE) {
        //Title:
        DrawText(" Toby The Meowstronaut", 135, 100, 40, Fade(RAYWHITE, glowAlpha));


        // Intructions:
        DrawText("Score up by Not hitting the Astroids", 220, 185, 20, Fade(RAYWHITE, glowAlpha));

        // Start Button:
    DrawRectangle(200,400,400,50, Fade(WHITE, glowAlpha));
        DrawRectangleLines(200,400,400,50, Fade(DARKPURPLE, glowAlpha));

        //Start Button:

        DrawText("PRESS SPACE TO START", 230, 415, 25, Fade(BLACK, glowAlpha));

    }
    else if (currentState == PLAYING) {



        DrawText(TextFormat("Score: %d", score),20,20,30,RAYWHITE);
    }
    // EndDrawing();

    // ClearBackground((Color){169,188,212,255});
    // DrawTexture(background, 0, 0, WHITE);
    // EndDrawing();
}

// Function for Score:
void Game::IncreaseScore() {
    score+=10;
}


void Game::Cleanup() {
    UnloadTexture(background);
}


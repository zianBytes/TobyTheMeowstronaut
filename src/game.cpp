// Tobby The Meowstronaut
// Implementation file for function definitions.

#include "game.h"
#include <cmath>

void Game::Init() {
    currentState = HOMEPAGE;
}

void Game::Update() {
    if (currentState == HOMEPAGE) {
        if(IsKeyPressed(KEY_SPACE)) {
            currentState = PLAYING;
        }
    }
}

void Game::Draw() {
    // Clear background differently for homepage and game screen
    if (currentState == HOMEPAGE) {
        ClearBackground(BLACK); // Homepage is completely black
    } else if (currentState == PLAYING) {
        ClearBackground((Color){186, 183, 231, 255}); // Light blue for gameplay
    }

    // Glow Effect using sin() function (unchanged)
    float glowAlpha = (sin(GetTime()*3.5) + 1) / 1;

    if (currentState == HOMEPAGE) {
        // Title:
        DrawText(" Toby The Meowstronaut", 135, 100, 40, RAYWHITE);

        // Instructions:
        DrawText("Score up by Not hitting the Asteroid", 220, 185, 20, LIGHTGRAY);

        // Start Button:
        DrawRectangle(200, 400, 400, 50, Fade(WHITE, glowAlpha));
        DrawRectangleLines(200, 400, 400, 50, Fade(DARKPURPLE, glowAlpha));
        DrawText("PRESS SPACE TO START", 230, 415, 25, Fade(BLACK, glowAlpha));
    }
    else if (currentState == PLAYING) {
        // Only show the score when in PLAYING mode
        DrawText(TextFormat("Score: %d", score), 20, 20, 30, BLACK);
    }
}

// Function for Score:
void Game::IncreaseScore() {
    score += 10;
}

void Game::Cleanup() {
    UnloadTexture(background);
}



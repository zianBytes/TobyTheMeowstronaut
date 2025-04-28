// Tobby The Meowstronaut
// Implementation file for function definitions.

#include "game.h"
#include <cmath>

void Game::Init() {
    currentState = HOMEPAGE;
    survivalTime = 0.0f;
    timerRunning = false;
}

void Game::Update() {
    if (currentState == HOMEPAGE) {
        if (IsKeyPressed(KEY_SPACE)) {
            currentState = PLAYING;
            survivalTime = 0.0f;
            timerRunning = true; // GamePage
        }
    }
    else if (currentState == PLAYING) {
        if (IsKeyPressed(KEY_P)) {
            currentState = PAUSED;
            timerRunning = false; // Paused
        }

        if (timerRunning) {
            survivalTime += GetFrameTime();// Timer While on Game Page
        }
        if (IsKeyPressed(KEY_E)) {
            currentState = YOUSUREVRO;
            timerRunning = true;
            survivalTime = 0.0f;
        }
    }
    else if (currentState == PAUSED) {
        if (IsKeyPressed(KEY_SPACE)) {
            currentState = PLAYING;
            timerRunning = true;   // Resume
        }
        else if (IsKeyPressed(KEY_E)) {
            currentState = HOMEPAGE;
            timerRunning = false;
            survivalTime = 0.0f; // Exit to HomePage
        }
    }
    else if (currentState == YOUSUREVRO) {
        if(IsKeyPressed(KEY_E)) {
            currentState = PLAYING;
            timerRunning = true;
            survivalTime = 0.0f;
        }
        else if (IsKeyPressed(KEY_SPACE)) {
            currentState = HOMEPAGE;
            timerRunning = false;
            survivalTime = 0.0f;
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
        DrawText("Score up by not hitting the Asteroids", 210, 185, 20, LIGHTGRAY);
        DrawText("While in the Game", 335, 240, 18, GRAY );
        DrawText("Press P to Pause", 210, 270, 18, BLUE);
        DrawText("Press E to Exit", 460, 270, 18, RED);

        // Start Button:
        DrawRectangle(200, 400, 400, 50, Fade(WHITE, glowAlpha));
        DrawRectangleLines(200, 400, 400, 50, Fade(DARKPURPLE, glowAlpha));
        DrawText("PRESS SPACE TO START", 230, 415, 25, Fade(BLACK, glowAlpha));
    }
    else if (currentState == PLAYING) {
        // Only show the score when in PLAYING mode
        DrawText(TextFormat("Time: %d", (int)survivalTime), 20, 20, 30, BLACK);
    }
    else if (currentState == PAUSED) {
        ClearBackground((Color){30, 30, 30, 255}); // Dark gray background when paused
        DrawText("GAME PAUSED", 250, 200, 40, RAYWHITE);
        DrawText("Press SPACE to Continue", 240, 300, 25, RAYWHITE);
        DrawText("Press E to Exit", 305, 350, 25, RAYWHITE);
    }
    else if (currentState == YOUSUREVRO) {
        ClearBackground((Color){30, 30, 30, 255});
        DrawText("EXIT", 345, 200, 40, RAYWHITE);
        DrawText("Press E to Exit Vro", 280, 280, 25, RAYWHITE);
        DrawText("Press Space to Resume Vro", 230, 320, 25, RAYWHITE);
    }
}

void Game::Cleanup() {
    // UnloadTexture(background);
}

GameState Game::GetState() {
    return currentState;
}



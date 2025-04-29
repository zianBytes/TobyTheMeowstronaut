#include "raylib.h"
#include "game.h"
#include "player.h"
#include "obstacle.h"
#include <vector> // To manage multiple obstacles

// Adding music and Sound Effects
// They're free and Non-Copyrighted
Music lobbyMusic;
Music gameplayMusic;
Sound clickSound;
Sound crashSound;
Sound gameOverSound;
Sound engineSound;
bool isEnginePlaying = false;


int main() {
    InitWindow(800, 600, "Toby The Meowstronaut");
    InitAudioDevice();
    SetTargetFPS(60);

    // Load Music:
    lobbyMusic = LoadMusicStream("assets/lobby.mp3"); // HomePage (Lobby)
    gameplayMusic = LoadMusicStream("assets/gamePage.mp3"); // GAME PAGE
    // Load Sound Effects:
    clickSound = LoadSound("assets/buttonPress.mp3");
    crashSound = LoadSound("assets/crash.mp3");
    gameOverSound = LoadSound("assets/gameOver.mp3");
    engineSound = LoadSound("assets/SpaceCraft.mp3");

    // Play Lobby Music when Game Starts:
    PlayMusicStream(lobbyMusic);


    Game game;
    Player player;

    std::vector<Obstacle> obstacles;
    float spawnTimer = 0.0f;
    const float spawnInterval = 2.0f; // Every 2 seconds spawn a new obstacle

    game.Init();
    player.Init();

    while (!WindowShouldClose()) {
        UpdateMusicStream(lobbyMusic);
        UpdateMusicStream(gameplayMusic);

        game.Update();

        if (game.GetState()==HOMEPAGE) {
            if (!IsMusicStreamPlaying(lobbyMusic)) {
                PlayMusicStream(lobbyMusic);
            }
            StopMusicStream(gameplayMusic);
            isEnginePlaying = false;
        }
        else if (game.GetState()==PLAYING) {
            if(!IsMusicStreamPlaying(gameplayMusic)) {
                PlayMusicStream(gameplayMusic);
            }
            StopMusicStream(lobbyMusic);

            if(!isEnginePlaying) {
                PlaySound(engineSound);
                isEnginePlaying = true;
            }
            if(!IsSoundPlaying(engineSound)) {
                PlaySound(engineSound);
            }
        }

        if (game.GetState() == PLAYING) {
            player.Update();

            // Update spawn timer
            spawnTimer += GetFrameTime();
            if (spawnTimer >= spawnInterval) {
                // Random gap Y position
                float gapY = GetRandomValue(100, 400);

                // Make speed increase slowly over time
                float speed = 4.0f + (game.GetSurvivalTime() / 5.0f);

                obstacles.push_back(Obstacle(800, gapY, 80, 150, speed));
                spawnTimer = 0.0f;
            }


            // Update obstacles
            for (auto& obs : obstacles) {
                obs.Update();
            }

            // Check Collisions:
            Rectangle playerRect = player.GetCollisionRect();
            for (auto& obs : obstacles) {
                if (CheckCollisionRecs(playerRect, obs.GetTopRect()) || CheckCollisionRecs(playerRect, obs.GetBottomRect())) {
                    PlaySound(crashSound);
                    game.SetGameOver(); // Collision happened!
                    PlaySound(gameOverSound);
                }
            }
        }
        else if (game.GetState() == GAMEOVER) {
            if (isEnginePlaying) {
                isEnginePlaying = false;
                StopSound(engineSound);
            }
            if (IsKeyPressed(KEY_R)) {
                game.SetPlaying();
                player.Init();
                obstacles.clear();
                spawnTimer = 0.0f;
            }
            else if (IsKeyPressed(KEY_E)) {
                game.SetHomepage();
                player.Init();
                obstacles.clear();
                spawnTimer = 0.0f;
            }
        }

        BeginDrawing();
        game.Draw();

        if (game.GetState() == PLAYING) {
            player.Draw(PLAYING);

            // Draw obstacles
            for (auto& obs : obstacles) {
                obs.Draw();
            }
        }

        EndDrawing();
    }
    UnloadMusicStream(lobbyMusic);
    UnloadMusicStream(gameplayMusic);
    UnloadSound(clickSound);
    UnloadSound(crashSound);
    UnloadSound(gameOverSound);
    UnloadSound(engineSound);
    CloseAudioDevice();

    player.Cleanup();
    game.Cleanup();
    CloseWindow();

    return 0;
}

#include "raylib.h"
#include "game.h"
#include "player.h"
#include "obstacle.h"
#include <vector> // To manage multiple obstacles

int main() {
    InitWindow(800, 600, "Toby The Meowstronaut");
    SetTargetFPS(60);

    Game game;
    Player player;

    std::vector<Obstacle> obstacles;
    float spawnTimer = 0.0f;
    const float spawnInterval = 2.0f; // Every 2 seconds spawn a new obstacle

    game.Init();
    player.Init();

    while (!WindowShouldClose()) {
        game.Update();

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
                    game.SetPaused(); // Collision happened!
                }
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

    player.Cleanup();
    game.Cleanup();
    CloseWindow();

    return 0;
}

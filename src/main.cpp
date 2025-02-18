#include "raylib.h"
#include "game.h"
#include "player.h"

int main() {

    InitWindow(800, 600, " Toby The Meowstronaut");
    SetTargetFPS(60);

    Game game;
    Player player;

    game.Init();
    player.Init();

    //Debug Line:
    // TraceLog(LOG_INFO, "Game is initializing...");
    // game.Init();
    // TraceLog(LOG_INFO, "Game initialized.");
    //
    // TraceLog(LOG_INFO, "Player is initializing...");
    // player.Init();
    // TraceLog(LOG_INFO, "Player initialized.");

    while (!WindowShouldClose()) {
        game.Update();
        player.Update();

        BeginDrawing();
        // ClearBackground((Color){10,10,20,225});
        game.Draw();

        // Only draw Toby when the game is in Playing Mode

        if (game.GetState() == PLAYING) {
            player.Draw(PLAYING);
        }
        EndDrawing();
    }
    player.Cleanup();
    game.Cleanup();

    CloseWindow();

    return 0;
}

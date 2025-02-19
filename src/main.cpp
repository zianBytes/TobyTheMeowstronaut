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

    while (!WindowShouldClose()) {
        game.Update();

        if (game.GetState() == PLAYING) {
            player.Update();
        }

        BeginDrawing();
        game.Draw();

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

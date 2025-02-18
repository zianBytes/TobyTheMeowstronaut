//
// Created by Zian Miad on 1/7/25.
//

#ifndef PLAYER_H
#define PLAYER_H
#include "raylib.h"
#include "game.h"

class Player {
private:
    Texture2D sprite;
    Vector2 position;
    int currentFrame = 0;
    float frameTime = 0.25f;
    float timer = 0.0f;
    int totalFrames = 2;


public:
    void Init();
    void Update();
    void Draw(GameState state);
    void Cleanup();
};

#endif //PLAYER_H

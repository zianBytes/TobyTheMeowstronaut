#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "raylib.h"

class Obstacle {
private:
    Rectangle topPillar;
    Rectangle bottomPillar;
    float speed;
    float gapHeight;

public:
    Obstacle(float startX, float gapY, float width, float gapSize, float spd);
    void Update();
    void Draw();
    Rectangle GetTopRect();
    Rectangle GetBottomRect();
};

#endif // OBSTACLE_H

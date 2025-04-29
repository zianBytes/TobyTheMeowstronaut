#include "obstacle.h"

Obstacle::Obstacle(float startX, float gapY, float width, float gapSize, float spd) {
    speed = spd;
    gapHeight = gapSize;
    topPillar = { startX, 0, width, gapY };
    bottomPillar = { startX, gapY + gapHeight, width, 600 - (gapY + gapHeight) };
}

void Obstacle::Update() {
    topPillar.x -= speed;
    bottomPillar.x -= speed;
}


void Obstacle::Draw() {
    // Gradient for Top Pillar
    for (int i = 0; i < (int)topPillar.height; i += 5) {
        float t = (float)i / (float)topPillar.height; // Gradient factor 0.0 to 1.0

        unsigned char r = (unsigned char)(200 * (1.0f - t) + 80 * t);
        unsigned char g = (unsigned char)(150 * (1.0f - t) + 0 * t);
        unsigned char b = (unsigned char)(255 * (1.0f - t) + 150 * t);

        DrawRectangle((int)topPillar.x, (int)i, (int)topPillar.width, 5, (Color){ r, g, b, 255 });
    }

    // Gradient for Bottom Pillar
    for (int i = 0; i < (int)bottomPillar.height; i += 5) {
        float t = (float)i / (float)bottomPillar.height;

        unsigned char r = (unsigned char)(200 * (1.0f - t) + 80 * t);
        unsigned char g = (unsigned char)(150 * (1.0f - t) + 0 * t);
        unsigned char b = (unsigned char)(255 * (1.0f - t) + 150 * t);

        DrawRectangle((int)bottomPillar.x, (int)(bottomPillar.y + i), (int)bottomPillar.width, 5, (Color){ r, g, b, 255 });
    }
}


Rectangle Obstacle::GetTopRect() {
    return topPillar;
}

Rectangle Obstacle::GetBottomRect() {
    return bottomPillar;
}



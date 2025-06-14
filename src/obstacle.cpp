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
    int topHeight = (int)topPillar.height;
    if (topHeight > 0 && topHeight < 600) {
        for (int i = 0; i < topHeight; i += 5) {
            float t = (float)i / topHeight;
            unsigned char r = (unsigned char)(255 * (1.0f - t) + 180 * t);
            unsigned char g = (unsigned char)(60 * (1.0f - t) + 20 * t);
            unsigned char b = (unsigned char)(60 * (1.0f - t) + 40 * t);

            DrawRectangle((int)topPillar.x, (int)i, (int)topPillar.width, 5, (Color){ r, g, b, 255 });
        }
    }

    // Gradient for Bottom Pillar
    int bottomHeight = (int)bottomPillar.height;
    if (bottomHeight > 0 && bottomHeight < 600) {
        for (int i = 0; i < bottomHeight; i += 5) {
            float t = (float)i / bottomHeight;
            unsigned char r = (unsigned char)(255 * (1.0f - t) + 180 * t);
            unsigned char g = (unsigned char)(60 * (1.0f - t) + 20 * t);
            unsigned char b = (unsigned char)(60 * (1.0f - t) + 40 * t);

            DrawRectangle((int)bottomPillar.x, (int)(bottomPillar.y + i), (int)bottomPillar.width, 5, (Color){ r, g, b, 255 });
        }
    }

}


Rectangle Obstacle::GetTopRect() {
    return topPillar;
}

Rectangle Obstacle::GetBottomRect() {
    return bottomPillar;
}



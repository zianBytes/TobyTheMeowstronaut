
#include "player.h"

void Player::Init() {
    sprite = LoadTexture("assets/toby_in_spaceship-sprite.png");
    position = { 35,200  }; // Start position in the middle
}

void Player::Update() {
    // Handle movement
    if (IsKeyDown(KEY_UP)) position.y -= 8;
    if (IsKeyDown(KEY_DOWN)) position.y += 8;

    // The following code is to make sure Toby don't go offscreen.
    // Total Frame of this game is 600 x 400
    int visibleHeight = sprite.height * 0.75;
    if (position.y < 0) {
        position.y = 0;
    }
    if (position.y > 600-(sprite.height * 1.25)) {
        position.y = 600-(sprite.height * 1.25);
    }
    // if (position.y > 600) {
    //     position.y = 600;

    // Update animation
    timer += GetFrameTime();  // Accumulate time
    if (timer >= frameTime) { // Switch frame every 250ms
        timer = 0.0f;
        //Old Animation Frametime Settings:
        // currentFrame++;
        // if (currentFrame >= totalFrames) currentFrame = 0; // Loop animation

        // New Animation Frame Time settings:
        currentFrame = (currentFrame+1) % totalFrames;
    }
}

void Player::Draw(GameState state) {

    if(state != PLAYING) {
        return;
    }

    int frameWidth = sprite.width / totalFrames; // Assuming frames are side by side
    int frameHeight = sprite.height;

    Rectangle frameRec = { (float)(currentFrame * frameWidth), 0.0f, (float)frameWidth, (float)sprite.height };

    // Scale the sprite by 1.5x
    Rectangle destRec = {position.x,position.y, frameWidth * 1.7f, frameHeight *1.7f};

    DrawTexturePro(sprite, frameRec, destRec, {0, 0}, 0.0f, WHITE);
}

void Player::Cleanup() {
    UnloadTexture(sprite);
}

Rectangle Player::GetCollisionRect() {
    int frameWidth = sprite.width / totalFrames;
    int frameHeight = sprite.height;

    float scaledWidth = frameWidth * 1.7f;
    float scaledHeight = frameHeight * 1.7f;

    Rectangle collisionBox;
    collisionBox.x = position.x + 10; // Shrink hitbox inside
    collisionBox.y = position.y + 10;
    collisionBox.width = scaledWidth - 20; // Slightly smaller width
    collisionBox.height = scaledHeight - 20; // Slightly smaller height

    return collisionBox;
}
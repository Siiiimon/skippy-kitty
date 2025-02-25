#ifndef PLAYER_H
#define PLAYER_H

#include "../util.h"
#include "raylib.h"
#include "stdlib.h"

#define PLAYER_WIDTH 50
#define PLAYER_HEIGHT 80

#define GRAVITY -70
#define JUMP_ACCELERATION 1100

enum JumpingState {
  JUMP_STATE_GROUNDED,
  JUMP_STATE_JUMPING,
};

struct Player {
  Rectangle* dimensions;
  enum JumpingState jump_state;
  float velocity;
  float acceleration;
};

struct Player* NewPlayer(Vector2 position);
void UpdatePlayer(struct Player* player, unsigned int ground_level);
void DrawPlayer(struct Player* player);
void FreePlayer(struct Player* player);

#endif /* PLAYER_H */

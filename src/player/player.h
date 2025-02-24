#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"
#include "stdlib.h"

#define PLAYER_WIDTH 50
#define PLAYER_HEIGHT 80

struct Player {
  Rectangle dimensions;
};

struct Player* NewPlayer(Vector2 position);
void UpdatePlayer(struct Player* player);
void DrawPlayer(struct Player* player);
void FreePlayer(struct Player* player);

#endif /* PLAYER_H */

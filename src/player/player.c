#include "player.h"
#include "raylib.h"

struct Player* NewPlayer(Vector2 position) {
  struct Player* player = malloc(sizeof(struct Player));
  player->dimensions = CLITERAL(Rectangle){position.x-PLAYER_WIDTH, position.y-PLAYER_HEIGHT, PLAYER_WIDTH, PLAYER_HEIGHT};

  return player;
}

void UpdatePlayer(struct Player* player) {
  return;
}

void DrawPlayer(struct Player* player) {
  DrawRectangleLinesEx(player->dimensions, 2.0f, CLITERAL(Color){0, 255, 0, 255});
}

void FreePlayer(struct Player* player) {
  free(player);
}

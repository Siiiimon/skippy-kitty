#include "player.h"
#include "raylib.h"

struct Player* NewPlayer(Vector2 position) {
  struct Player* player = malloc(sizeof(struct Player));
  Rectangle* dim = malloc(sizeof(Rectangle));
  dim->x = position.x-PLAYER_WIDTH;
  dim->y = position.y-PLAYER_HEIGHT;
  dim->width = PLAYER_WIDTH;
  dim->height = PLAYER_HEIGHT;
  player->dimensions = dim;
  player->jump_state = JUMP_STATE_GROUNDED;
  player->velocity = 0;
  player->acceleration = 0;

  return player;
}

void UpdatePlayer(struct Player* player, unsigned int ground_level) {
  float delta_time = GetFrameTime();

  if (player->jump_state == JUMP_STATE_JUMPING) {
    player->acceleration += GRAVITY;
  }

  if (IsKeyPressed(KEY_SPACE) && player->jump_state == JUMP_STATE_GROUNDED) {
    player->acceleration += JUMP_ACCELERATION;
    player->jump_state = JUMP_STATE_JUMPING;
  }

  player->velocity += player->acceleration * delta_time;
  player->dimensions->y -= player->velocity * delta_time;

  if (player->dimensions->y >= ground_level-player->dimensions->height) {
    player->dimensions->y = ground_level-player->dimensions->height;
    player->acceleration = 0;
    player->velocity = 0;
    player->jump_state = JUMP_STATE_GROUNDED;
  }
      
  return;
}

void DrawPlayer(struct Player* player) {
  DrawRectangleLinesEx(*player->dimensions, 2.0f, CLITERAL(Color){0, 255, 0, 255});
  DebugText(TextFormat("acceleration: %f", player->acceleration));
  DebugText(TextFormat("velocity: %f", player->velocity));
  DebugText(TextFormat("Y position: %f", player->dimensions->y));
}

void FreePlayer(struct Player* player) {
  free(player->dimensions);
  free(player);
}

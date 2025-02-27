#include "puddle.h"
#include "raylib.h"

struct Puddle* NewPuddle(Vector2 position) {
  struct Puddle* puddle = malloc(sizeof(struct Puddle));
  struct Rectangle* dimensions = malloc(sizeof(Rectangle));
  dimensions->x = position.x;
  dimensions->y = position.y;
  dimensions->width = PUDDLE_WIDTH;
  dimensions->height = PUDDLE_HEIGHT;
  puddle->dimensions = dimensions;
  return puddle;
}

void UpdatePuddle(struct Puddle* puddle, float scroll) {
  puddle->dimensions->x -= scroll;
  return;
}

void DrawPuddle(struct Puddle* puddle) {
    DrawCircle(puddle->dimensions->x, puddle->dimensions->y, 5, RED);
  DrawRectangleLinesEx(*puddle->dimensions, 2.0f, RED);
}

int ShouldFreePuddle(struct Puddle* puddle) {
    return puddle->dimensions->x < -puddle->dimensions->width;
}

int IsPuddleKillingPlayer(struct Puddle* puddle, Rectangle* player) {
    return (puddle->dimensions->x + puddle->dimensions->width >= player->x && player->x + player->width >= puddle->dimensions->x);
}

void FreePuddle(struct Puddle* puddle) {
  free(puddle->dimensions);
  free(puddle);
}

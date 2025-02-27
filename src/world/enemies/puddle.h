#ifndef PUDDLE_H
#define PUDDLE_H

#include "raylib.h"
#include "stdlib.h"

#define PUDDLE_WIDTH 20
#define PUDDLE_HEIGHT 15

struct Puddle {
  Rectangle* dimensions;
};

struct Puddle* NewPuddle(Vector2 position);
void UpdatePuddle(struct Puddle* puddle, float scroll);
void DrawPuddle(struct Puddle* puddle);
int IsPuddleKillingPlayer(struct Puddle* puddle, Rectangle* player);
int ShouldFreePuddle(struct Puddle* puddle);
void FreePuddle(struct Puddle* puddle);

#endif /* PUDDLE_H */

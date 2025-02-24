#ifndef GROUND_H
#define GROUND_H

#include "raylib.h"
#include "stdlib.h"
#include "sediment.h"

struct Ground {
  Rectangle rect;
  Color color;
  Image base;
  struct Sediment* dark;
  struct Sediment* light;
  struct Sediment* pebbles;
  Texture tex;
};


struct Ground* NewGround(int x, int y, int width, int height);
void UpdateGround(struct Ground* s, int offset);
void DrawGround(struct Ground* s, Color color);
void UnloadGround(struct Ground* s);


#endif /* GROUND_H */

#ifndef SURFACE_H
#define SURFACE_H

#include "raylib.h"
#include "stdlib.h"

struct Surface {
  Rectangle rect;
  float scale;
  Image img;
  Texture tex;
};

struct Surface* InitSurface(int x, int y, int width, int height, float scale);
void UpdateSurface(struct Surface* s, int offset);
void DrawSurface(struct Surface* s, Color color);
void UnloadSurface(struct Surface* s);

#endif /* SURFACE_H */

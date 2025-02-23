#include "surface.h"

struct Surface* InitSurface(int x, int y, int width, int height, float scale) {
  Rectangle r = {
    .x = x,
    .y = y,
    .width = width,
    .height = height
  };
  Image i = GenImagePerlinNoise(width, height, 0, 0, scale);
  Texture t = LoadTextureFromImage(i);
  struct Surface* s = malloc(sizeof(struct Surface));
  s->rect = r;
  s->scale = scale;
  s->img = i;
  s->tex=t;
  return s;
}

void UpdateSurface(struct Surface* s, int offset) {
  s->img = GenImagePerlinNoise(s->rect.width, s->rect.height, offset, 0, s->scale);
  UpdateTexture(s->tex, s->img.data);
}

void DrawSurface(struct Surface* s, Color color) {
  DrawTexture(s->tex, 0, s->rect.y, color);
}

void UnloadSurface(struct Surface* s) {
  UnloadTexture(s->tex);
  UnloadImage(s->img);
}

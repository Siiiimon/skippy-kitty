#include "ground.h"
#include "raylib.h"


struct Ground* NewGround(int x, int y, int width, int height) {
  Rectangle r = {
    .x = x,
    .y = y,
    .width = width,
    .height = height
  };
  Color c = CLITERAL(Color){152, 85, 52, 255};
  Image b = GenImageColor(width, height, c);
  Texture t = LoadTextureFromImage(b);
  struct Sediment* d = NewSediment(r, CLITERAL(Color){86, 41, 19, 255}, 42, 4.0f, 2, 110);
  struct Sediment* l = NewSediment(r, CLITERAL(Color){150, 110, 61, 255}, 43, 3.0f, 1, 70);
  struct Sediment* p = NewSediment(r, CLITERAL(Color){137, 137, 137, 255}, 44, 5.0f, 1, 40);
  struct Ground* g = malloc(sizeof(struct Ground));
  g->rect = r;
  g->color = c;
  g->base = b;
  g->dark = d;
  g->light = l;
  g->pebbles = p;
  g->tex = t;
  return g;
}

void UpdateGround(struct Ground* g, int offset) {
  UpdateSediment(g->dark, offset);
  UpdateSediment(g->light, offset);
  UpdateSediment(g->pebbles, offset);

  g->base = GenImageColor(g->rect.width, g->rect.height, g->color);
  ImageDraw(
            &g->base,
            g->dark->img,
            CLITERAL(Rectangle){0, 0, g->base.width, g->base.height},
            CLITERAL(Rectangle){0, 0, g->base.width, g->base.height},
            WHITE
  );
  ImageDraw(
            &g->base,
            g->light->img,
            CLITERAL(Rectangle){0, 0, g->base.width, g->base.height},
            CLITERAL(Rectangle){0, 0, g->base.width, g->base.height},
            WHITE
  );
  ImageDraw(
            &g->base,
            g->pebbles->img,
            CLITERAL(Rectangle){0, 0, g->base.width, g->base.height},
            CLITERAL(Rectangle){0, 0, g->base.width, g->base.height},
            WHITE
  );
  UpdateTexture(g->tex, g->base.data);
}

void DrawGround(struct Ground* g, Color color) {
  DrawTexture(g->tex, 0, g->rect.y, color);
}

void UnloadGround(struct Ground* g) {
  UnloadTexture(g->tex);
  UnloadImage(g->base);
  free(g);
}

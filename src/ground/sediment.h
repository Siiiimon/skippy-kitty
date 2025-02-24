#ifndef SEDIMENT_H
#define SEDIMENT_H

#include "raylib.h"
#include "stdlib.h"

struct Sediment {
  Rectangle dimensions;
  Image img;
  Color color;
  unsigned int seed;
  float scale;
  int threshold;
  int blur;
};

struct Sediment* NewSediment(Rectangle dimensions, Color color, unsigned int seed, float scale, int blur, int threshold);
void ApplySedimentFilters(Image* raw, Color color, int blur, int threshold);
void UpdateSediment(struct Sediment* sediment, int offset);
void UnloadSediment(struct Sediment* sediment);

#endif /* SEDIMENT_H */

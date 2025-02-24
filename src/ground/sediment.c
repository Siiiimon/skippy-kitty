#include "sediment.h"
#include "raylib.h"

struct Sediment* NewSediment(Rectangle dimensions, Color color, unsigned int seed, float scale, int blur, int threshold) {
  struct Sediment* sed = malloc(sizeof(struct Sediment));
  SetRandomSeed(seed);
  Image img = GenImagePerlinNoise(dimensions.width, dimensions.height, 0, 0, scale);
  Texture tex = LoadTextureFromImage(img);
  ApplySedimentFilters(&img, color, blur, threshold);
  sed->dimensions = dimensions;
  sed->img = img;
  sed->color = color;
  sed->seed = seed;
  sed->scale = scale;
  sed->blur = blur;
  sed->threshold = threshold;
  return sed;
}

void ApplySedimentFilters(Image* raw, Color color, int blur, int threshold) {
  ImageBlurGaussian(raw, blur);
  if (raw->format == PIXELFORMAT_UNCOMPRESSED_R8G8B8A8) {
    Color* pixels = (Color*)raw->data;
    for (int xy = 0; xy < raw->width * raw->height; xy++) {
      if (pixels[xy].r < threshold) {
        pixels[xy] = color;
      } else {
        pixels[xy].a = 0;
      }
    }
  } else {
    TraceLog(LOG_ERROR, "perlin noise image in unexpected format: %d", raw->format);
  }
}

void UpdateSediment(struct Sediment* sediment, int offset) {
  SetRandomSeed(sediment->seed);
  sediment->img = GenImagePerlinNoise(sediment->dimensions.width, sediment->dimensions.height, offset, 0, sediment->scale);
  ApplySedimentFilters(&sediment->img, sediment->color, sediment->blur, sediment->threshold);
}

void UnloadSediment(struct Sediment* sediment) {
  UnloadImage(sediment->img);
  free(sediment);
}

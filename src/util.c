#include "util.h"

unsigned int debug_lines = 0;

void DebugText(const char* text) {
  #ifdef DEBUG
  int width = MeasureText(text, 12);

  DrawText(text, GetScreenWidth() - width, debug_lines * 18, 12, BLACK);
  debug_lines++;
  #endif
}

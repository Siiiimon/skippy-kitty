#include "director.h"
#include "raylib.h"
#include "world/enemies/puddle.h"

struct Director *NewDirector(int budget) {
  struct Director *director = malloc(sizeof(struct Director));
  director->budget = budget;
  director->last_spawn_time = 0;
  director->puddle_amount = 0;
  director->puddles = malloc(MAX_PUDDLES * sizeof(struct Puddle *));
  return director;
}

void SpawnEnemies(struct Director *director, float ground_level) {
  // puddles
  if (director->budget >= puddle_spawn_cost) {
    if (GetRandomValue(0, 100) > puddle_spawn_chance) {
      if (director->puddle_amount < MAX_PUDDLES) {
        director->puddles[director->puddle_amount] =
            NewPuddle(CLITERAL(Vector2){GetScreenWidth() - 50, ground_level});
        director->puddle_amount++;
        TraceLog(LOG_INFO, "UpdateDirector: spawned new puddle");
      } else {
        TraceLog(LOG_ERROR, "UpdateDirector: puddle array is full!");
      }
    }
    // if we didn't spawn a puddle because we failed the spawn chance, still reset the spawn timer for additonal randomness
    director->last_spawn_time = GetTime();
  }
}

void UpdateDirector(struct Director *director, float ground_level,
                    float scroll) {
  director->budget += CREDIT_REGEN_RATE;

  // check if we're still on spawn cooldown
  if (GetTime() - director->last_spawn_time >= SPAWN_COOLDOWN)
    SpawnEnemies(director, ground_level);

  // update enemies
  for (size_t i = 0; i < director->puddle_amount; i++) {
    UpdatePuddle(director->puddles[i], scroll);
    // TODO this should be a 'shouldDespawn' function or something
    if (ShouldFreePuddle(director->puddles[i])) {
      FreePuddle(director->puddles[i]);
      TraceLog(LOG_INFO, "UpdateDirector: Freed Puddle %d", i);

      if (i < director->puddle_amount - 1) {
        director->puddles[i] = director->puddles[director->puddle_amount - 1];
        i--;
      }

      director->puddle_amount--;
    }
  }
}

void DrawDirector(struct Director *director) {
  for (size_t i = 0; i < director->puddle_amount; i++) {
    DrawPuddle(director->puddles[i]);
  }
}

void FreeDirector(struct Director *director) {
  for (size_t i = 0; i < director->puddle_amount; i++) {
    FreePuddle(director->puddles[i]);
  }
  free(director->puddles);
  free(director);
}

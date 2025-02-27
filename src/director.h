#ifndef DIRECTOR_H
#define DIRECTOR_H

#include "world/enemies/puddle.h"
#include "stdlib.h"

#define CREDIT_REGEN_RATE 1
#define SPAWN_COOLDOWN 1
#define MAX_PUDDLES 24

static const int puddle_spawn_cost = 3;
static const int puddle_spawn_chance = 40;

struct Director {
  int budget;
  double last_spawn_time;

  // enemies
  int puddle_amount;
  struct Puddle** puddles;
};

struct Director* NewDirector(int budget);
void SpawnEnemies(struct Director* director, float ground_level);
void UpdateDirector(struct Director* director, float ground_level, float scroll);
void DrawDirector(struct Director* director);
void FreeDirector(struct Director* director);

#endif /* DIRECTOR_H */

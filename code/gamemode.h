#pragma once

#include <vector>

#include "asteroid.h"
#include "player.h"

class Gamemode {
 public:
  Gamemode();
  bool update(float delta_time);

 private:
  Player player;
  std::vector<Asteroid> debris;
  int score;
};
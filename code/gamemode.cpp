#include "gamemode.h"

Gamemode::Gamemode() : player(Player()), score(0) {}

bool Gamemode::update(float delta_time) {
  if (player.update(delta_time)) {
    return true;
  }

  bool scores_changed = false;

  for (Asteroid asteroid : debris) {
    if (asteroid.update(delta_time)) {
      score++;
      scores_changed = true;
    }
  }

  erase_if(debris, [](Asteroid a) { return !a.isAlive(); });

  if (scores_changed) {
    player.updateScore(score);
    for (Asteroid asteroid : debris) {
      asteroid.updateScore(score);
    }
  }
  return false;
}
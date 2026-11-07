#include "gamemode.h"

Gamemode::Gamemode(sf::RenderWindow* window, ResourceManager* manager)
    : window(window),
      manager(manager),
      player(Player(window, manager->getShipTexture(),
                    manager->getMissileTexture())),
      score(0), debris_cd(0) {}

bool Gamemode::update(float delta_time) {
  if (player.update(delta_time)) {
    return true;
  }
  debris_cd -= delta_time;
  if (debris_cd <= 0) {
    debris_cd = 2;
    debris.push_back(Asteroid(score, window, manager->getAsteroidTexture()));
  }

  bool scores_changed = false;

  for (Asteroid& asteroid : debris) {
    if (asteroid.update(delta_time)) {
      score++;
      scores_changed = true;
    }
  }

  erase_if(debris, [](Asteroid a) { return !a.isAlive() || a.isTooFar(); });

  if (scores_changed) {
    player.updateScore(score);
    for (Asteroid asteroid : debris) {
      asteroid.updateScore(score);
    }
  }
  return false;
}

int Gamemode::getScore() { return score; }

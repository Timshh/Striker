#include "gamemode.h"

Gamemode::Gamemode(sf::RenderWindow* window, ResourceManager* manager)
    : window(window),
      manager(manager),
      player(Player(window, manager->getShipTexture(),
                    manager->getMissileTexture())),
      score_text(*manager->getFont(), "Score: 0", 20),
      health_text(*manager->getFont(), "3 HP", 20),
      score(0),
      debris_cd(0) {
  score_text.setPosition(sf::Vector2f(10, 10));
  health_text.setPosition(sf::Vector2f(550, 10));
}

bool Gamemode::update(float delta_time) {
  if (player.update(delta_time)) {
    return true;
  }
  debris_cd -= delta_time;
  if (debris_cd <= 0) {
    debris_cd = 1;
    debris.push_back(Asteroid(score, window, manager->getAsteroidTexture()));
  }

  bool scores_changed = false;

  for (Asteroid& asteroid : debris) {
    if (!asteroid.update(delta_time)) {
      for (Missile& missile : *player.getMissiles()) {
        if (asteroid.getBody()->getGlobalBounds().findIntersection(
                missile.getBody()->getGlobalBounds())) {
          asteroid.takeDamage(1);
          missile.takeDamage(1);
          score++;
          scores_changed = true;
          break;
        }
      }
      if (asteroid.getBody()->getGlobalBounds().findIntersection(
              player.getBody()->getGlobalBounds())) {
        asteroid.takeDamage(1);
        player.takeDamage(1);
        health_text.setString(std::to_string(player.getHP()) + " HP");
      }
    }
  }
  window->draw(score_text);
  window->draw(health_text);
  erase_if(debris, [](Asteroid& a) { return !a.isAlive() || a.isTooFar(); });

  if (scores_changed) {
    score_text.setString("Score: " + std::to_string(score));
    player.updateScore(score);
    for (Asteroid asteroid : debris) {
      asteroid.updateScore(score);
    }
  }
  return false;
}

int Gamemode::getScore() { return score; }

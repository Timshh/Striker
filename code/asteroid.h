#pragma once

#include "object.h"

class Asteroid : public Object {
 public:
  Asteroid(int score, sf::RenderWindow* window, sf::Texture* texture);
  bool update(float delta_time) override;
  bool isTooFar();
  void takeDamage(int damage) override;
  void updateScore(int new_score);

 private:
  float move_speed;
};
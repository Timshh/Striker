#pragma once

#include "object.h"

class Asteroid : public Object {
 public:
  Asteroid(int score);
  bool update(float delta_time) override;
  void takeDamage(int damage) override;
  void updateScore(int new_score);

 private:
  float move_speed;
};
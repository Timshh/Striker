#pragma once

#include "object.h"

class Player : public Object {
 public:
  Player();
  bool update(float delta_time) override;
  void takeDamage(int damage) override;
  void updateScore(int new_score);

 private:
  float fire_speed, fire_cd;
};
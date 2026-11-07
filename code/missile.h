#pragma once

#include "object.h"

class Missile : public Object {
 public:
  Missile(sf::RenderWindow* window, sf::Texture* texture);
  bool update(float delta_time) override;
  bool isTooFar();
  void takeDamage(int damage) override;

 private:
  float move_speed;
};
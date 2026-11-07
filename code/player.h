#pragma once

#include "object.h"
#include "missile.h"

class Player : public Object {
 public:
  Player(sf::RenderWindow* window, sf::Texture* ship_texture, sf::Texture* missile_texture);
  bool update(float delta_time) override;
  void takeDamage(int damage) override;
  void updateScore(int new_score);

 private:
  sf::Texture* missile_texture;
  std::vector<Missile> missiles;
  float fire_speed, fire_cd, position;
};
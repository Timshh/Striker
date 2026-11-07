#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include "resource_manager.h"

class Object {
 public:
  Object(int health, sf::RenderWindow* window, sf::Texture* texture);
  bool isAlive();
  virtual bool update(float delta_time);
  virtual void takeDamage(int damage);

 protected:
  sf::RenderWindow* window;
  sf::Sprite body;
  bool alive;
  int health;
};
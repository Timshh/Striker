#include "missile.h"

Missile::Missile(sf::RenderWindow* window, sf::Texture* texture,
                 sf::Vector2f position)
    : Object(1, window, texture) {
  body.setPosition(position);
}

bool Missile::update(float delta_time) {
  body.setPosition(body.getPosition() + sf::Vector2f(0, delta_time * -300));
  return Object::update(delta_time);
}

bool Missile::isTooFar() {
  if (body.getPosition().y < -100) {
    return true;
  }
  return false;
}

void Missile::takeDamage(int damage) { Object::takeDamage(damage); }
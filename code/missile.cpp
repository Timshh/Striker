#include "missile.h"

Missile::Missile(sf::RenderWindow* window, sf::Texture* texture)
    : Object(1, window, texture) {}
bool Missile::update(float delta_time) {
  body.setPosition(body.getPosition() + sf::Vector2f(0, 100 * delta_time));
  return Object::update(delta_time);
}

bool Missile::isTooFar() { return false; }

void Missile::takeDamage(int damage) { Object::takeDamage(damage); }
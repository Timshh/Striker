#include "object.h"

Object::Object(int health, sf::RenderWindow* window, sf::Texture* texture)
    : window(window), health(health), alive(true), body(*texture) {
  body.setOrigin(sf::Vector2f(body.getTexture().getSize().x / 2,
                              body.getTexture().getSize().y / 2));
}

bool Object::isAlive() { return alive; }

bool Object::update(float delta_time) {
  window->draw(body);
  if (!alive) {
    return true;
  }
  return false;
};

void Object::takeDamage(int damage) {
  health -= damage;
  if (health <= 0) {
    alive = false;
  }
};
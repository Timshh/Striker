#include "asteroid.h"

Asteroid::Asteroid(int score, sf::RenderWindow* window, sf::Texture* texture)
    : Object(1, window, texture) {
  body.setPosition(sf::Vector2f(20 + rand() % 560, -100));
  body.setRotation(sf::Angle(sf::radians(rand() % 100)));
  updateScore(score);
}

bool Asteroid::update(float delta_time) {
  body.setPosition(body.getPosition() +
                   sf::Vector2f(0, delta_time * move_speed));
  return Object::update(delta_time);
}

bool Asteroid::isTooFar() {
  if (body.getPosition().y > 1000) {
    return true;
  }
  return false;
}

void Asteroid::takeDamage(int damage) { Object::takeDamage(damage); }

void Asteroid::updateScore(int new_score) { move_speed = 100 + new_score * 5; };
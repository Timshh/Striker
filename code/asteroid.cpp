#include "asteroid.h"

Asteroid::Asteroid(int score, sf::RenderWindow* window, sf::Texture* texture)
    : Object(1, window, texture) {
  updateScore(score);
}

bool Asteroid::update(float delta_time) {
  body.setPosition(body.getPosition() + sf::Vector2f(0, -100 * delta_time));
  return Object::update(delta_time);
}

bool Asteroid::isTooFar() { return false; }

void Asteroid::takeDamage(int damage) { Object::takeDamage(damage); }

void Asteroid::updateScore(int new_score) {
  move_speed = 1 + new_score / 100.0;
};
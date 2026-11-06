#include "player.h"

Player::Player() : Object(3), fire_speed(1), fire_cd(0) {}

bool Player::update(float delta_time) { return false; }

void Player::takeDamage(int damage) {
  Object::takeDamage(damage);
}

void Player::updateScore(int new_score) { fire_speed = 1 + new_score / 25; };
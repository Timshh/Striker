#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>
#include <vector>

#include "asteroid.h"
#include "player.h"

class Gamemode {
 public:
  Gamemode(sf::RenderWindow* window, ResourceManager* manager);
  bool update(float delta_time);
  int getScore();

 private:
  sf::Text score_text, health_text;
  ResourceManager* manager;
  sf::RenderWindow* window;
  Player player;
  std::vector<Asteroid> debris;
  float debris_cd;
  int score;
};
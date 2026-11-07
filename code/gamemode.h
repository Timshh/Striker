#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <vector>

#include "asteroid.h"
#include "player.h"

class Gamemode {
 public:
  Gamemode(sf::RenderWindow* window, ResourceManager* manager);
  bool update(float delta_time);
  int getScore();

 private:
  ResourceManager* manager;
  sf::RenderWindow* window;
  Player player;
  std::vector<Asteroid> debris;
  float debris_cd;
  int score;
};
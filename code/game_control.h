#pragma once

#include <memory>
#include <ctime>
#include <SFML/Graphics/RenderWindow.hpp>

#include "gamemode.h"
#include "resource_manager.h"

enum class GameStates { kMenu, kPlaying };

class GameControl {
 public:
  GameControl();
  void run();
  void update();

 private:
  sf::RenderWindow window;
  sf::Clock time;
  ResourceManager manager;
  std::unique_ptr<Gamemode> gamemode;
  GameStates state;
  int high_score;
};
#pragma once

#include <memory>

#include "gamemode.h"

enum class GameStates { kMenu, kPlaying };

class GameControl {
 public:
  GameControl();
  void Update(float delta_time);

 private:
  std::unique_ptr<Gamemode> gamemode;
  GameStates state;
  int high_score;
};
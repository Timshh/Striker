#include "game_control.h"

GameControl::GameControl() : state(GameStates::kMenu), high_score(0) {
  gamemode.reset(new Gamemode());
  state = GameStates::kPlaying;
}

void GameControl::Update(float delta_time) {
  switch (state) {
    case GameStates::kMenu:
      break;
    case GameStates::kPlaying:
      gamemode->update(delta_time);
      break;
  }
};
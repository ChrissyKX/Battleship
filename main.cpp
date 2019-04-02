#include "Controller.h"

#include <iostream>
#include <vector>
#include <algorithm>

using namespace BattleShip;

int main(int argc, char** argv) {
  auto controller = Controller();
  if(argc == 3){
    controller.setupGame(argv[1], std::stoi(argv[2]));
  }else if(argc == 2){
    controller.setupGame(argv[1]);
  }else if(argc == 1){
    controller.setupGame();
  }
  controller.playGame();
  return 0;
}
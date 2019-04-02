//
// Created by mfbut on 3/11/2019.
//

#ifndef BATTLESHIP_CHEATINGAI_H
#define BATTLESHIP_CHEATINGAI_H
#include "AiPlayer.h"

namespace BattleShip {
class CheatingAI  : public AiPlayer{
 public:
  CheatingAI(const GameAttributes& gameAttributes, View& view);
  virtual std::unique_ptr<Move> getMove() override;
    void setShipPosition();
    virtual void placeShips() override;
  //new member
protected:
  std::vector<std::pair<int, int>> shipPosition;
  int flag = 0;
};
}

#endif //BATTLESHIP_CHEATINGAI_H

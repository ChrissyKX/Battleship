//
// Created by mfbut on 3/11/2019.
//

#ifndef BATTLESHIP_HUNTDESTROYAI_H
#define BATTLESHIP_HUNTDESTROYAI_H
#include <vector>
#include <algorithm>
#include "RandomAI.h"
namespace BattleShip {
class HuntDestroyAI : public RandomAI{
 public:
  HuntDestroyAI(const GameAttributes& gameAttributes, View& view);
  virtual std::unique_ptr<Move> getMove() override;
 protected:

  void setQueue(int row, int col) ;
  void eraseElement(int row,int col);

  std::vector<std::pair<int,int>> priorityFiringQueue;

};
}

#endif //BATTLESHIP_HUNTDESTROYAI_H

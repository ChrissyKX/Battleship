//
// Created by mfbut on 3/11/2019.
//

#include <algorithm>
#include "HuntDestroyAI.h"
#include "Attack.h"
#include "Utility.h"

using namespace BattleShip;

HuntDestroyAI::HuntDestroyAI(const GameAttributes& gameAttributes, View& view):RandomAI(gameAttributes, view){

}
std::unique_ptr<Move> HuntDestroyAI::getMove(){
    int row, col;
    if(priorityFiringQueue.empty()) {
        auto itr = chooseRandom(firingLocations, randomNumberGenerator);
        row = (*itr).first;
        col = (*itr).second;
        auto move = std::make_unique<Attack>(Attack(*this, row, col));
        firingLocations.erase(itr);
        if (getOpponent().getBoard().at(row, col).containsShip()) {
            setQueue(row, col);
        }
        return move;
    } else {
        row = priorityFiringQueue[0].first;
        col = priorityFiringQueue[0].second;
        auto move = std::make_unique<Attack>(Attack(*this, row, col));
        if(getOpponent().getBoard().at(row, col).containsShip()){
            setQueue(row, col);
        }
        priorityFiringQueue.erase(priorityFiringQueue.begin());
        return move;
    }

}

//set surrounding coordinates if the center was hit and contained ship.
void HuntDestroyAI::setQueue(int row, int col){
    Board& temp = getOpponent().getBoard();
    if(temp.inBounds(row, col-1)&&!temp.at(row, col-1).HasBeenFiredAt()){
        priorityFiringQueue.push_back(std::pair<int, int>(row, col-1));
        eraseElement(row, col-1);
    }
    if(temp.inBounds(row-1, col)&&!temp.at(row-1, col).HasBeenFiredAt()){
        priorityFiringQueue.push_back(std::pair<int, int>(row-1, col));
        eraseElement(row-1, col);
    }
    if(temp.inBounds(row, col+1)&&!temp.at(row, col+1).HasBeenFiredAt()){
        priorityFiringQueue.push_back(std::pair<int, int>(row, col+1));
        eraseElement(row, col+1);
    }
    if(temp.inBounds(row+1, col)&&!temp.at(row+1, col).HasBeenFiredAt()){
        priorityFiringQueue.push_back(std::pair<int, int>(row+1, col));
        eraseElement(row+1, col);
    }
}

void HuntDestroyAI::eraseElement(int row, int col) {
    for (auto itr = firingLocations.begin(); itr!=firingLocations.end(); ++itr){
        if((*itr).first == row && (*itr).second == col){
            firingLocations.erase(itr);
            break;
        }
    }
}


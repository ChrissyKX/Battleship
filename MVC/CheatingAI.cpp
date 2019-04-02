//
// Created by mfbut on 3/11/2019.
//
#include <stdexcept>
#include "CheatingAI.h"
#include "Attack.h"

using namespace BattleShip;

CheatingAI::CheatingAI(const GameAttributes& gameAttributes, View& view) : AiPlayer(gameAttributes, view){
}

void CheatingAI::setShipPosition(){
    for (int i = 0; i<getOpponent().getBoard().getNumRows(); ++i){
        for(int k = 0; k<getOpponent().getBoard().getNumCols(); ++k){
            if(getOpponent().getBoard().at(i, k).containsShip()){
                shipPosition.emplace_back(std::pair<int, int>(i, k));
            }
        }

    }
}

std::unique_ptr<Move> CheatingAI::getMove(){
    if(flag<1){
        setShipPosition();
        flag++;
    }
    auto attack =  std::make_unique<Attack>(Attack(*this, shipPosition[0].first, shipPosition[0].second));
    shipPosition.erase(shipPosition.begin());
    return attack;

}

void CheatingAI::placeShips() {
    AiPlayer::placeShips();
}
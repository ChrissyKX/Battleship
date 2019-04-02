//
// Created by mfbut on 3/9/2019.
//

#include <utility>
#include "HumanPlayer.h"
#include "ShipPlacement.h"
#include "Attack.h"

using namespace BattleShip;

HumanPlayer::HumanPlayer(const GameAttributes& gameAttributes, View& view): Player(gameAttributes, view){
}

std::unique_ptr<Move> HumanPlayer::getMove(){
    auto pair = view.getFiringCoordinate(*this);
    return std::make_unique<Attack>(Attack(*this, pair.first, pair.second));
}
void HumanPlayer::placeShips(){
    view.showPlacementBoard(*this);
    for(auto& x : shipHealths) {
        board.AddShip(x.first, view.getShipPlacement(*this, x.first, x.second));
        view.showPlacementBoard(*this);
    }
}

void HumanPlayer::initializeName(){
    name = view.getPlayerName(id);
}
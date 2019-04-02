//
// Created by mfbut on 3/10/2019.
//

#include "EndGame.h"

using namespace BattleShip;

EndGame::EndGame(Player& moveMaker):Move(moveMaker){
}
void EndGame::enact(Model& model, View& view){
    if(moveMaker.allShipsSunk()){
        model.endGame();
        view.showWinner(model.getWinner());
    }
}
bool EndGame::isValid() const {return true;}
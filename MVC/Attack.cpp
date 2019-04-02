//
// Created by mfbut on 3/10/2019.
//

#include "Attack.h"

using namespace BattleShip;

Attack::Attack(Player& attacker, int row, int col): Move(attacker), row(row), col(col){

}

bool Attack::isValid() const{
    return moveMaker.getOpponent().getBoard().inBounds(row, col) && (!moveMaker.getOpponent().getBoard().at(row, col).HasBeenFiredAt());
}

const int Attack::getRow() const{
    return row;
}
const int Attack::getCol() const{
    return col;
}

void Attack::enact(Model &model, View &view) {
    auto result = moveMaker.getOpponent().firedAt(row, col);
    view.showResultOfAttack(moveMaker, result);
    model.changeTurn();
}

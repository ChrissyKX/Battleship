//
// Created by mfbut on 3/11/2019.
//

#include "RandomAI.h"
#include "Attack.h"
#include "Utility.h"

using namespace BattleShip;

RandomAI::RandomAI(const BattleShip::GameAttributes &gameAttributes, BattleShip::View &view) : AiPlayer(gameAttributes, view){
    for(int i = 0; i<getBoard().getNumRows(); ++i){
        for(int k =0; k<getBoard().getNumCols(); ++k){
            firingLocations.push_back(std::pair<int, int>(i, k));
        }
    }
}
std::unique_ptr<Move> RandomAI::getMove() {
    auto itr = chooseRandom(firingLocations, randomNumberGenerator);
    auto attack = std::make_unique<Attack>(Attack(*this, (*itr).first, (*itr).second));
    firingLocations.erase(itr);
    return attack;
}

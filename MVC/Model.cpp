//
// Created by mfbut on 3/9/2019.
//

#include <fstream>
#include <algorithm>
#include "Model.h"

namespace BattleShip {
    Model::Model(){
        gameAttributes = GameAttributes();
        playerTurn  = 0;
        forcedGameOver  = false;
    }

    Player& Model::getAttackingPlayer(){
        return *(players[playerTurn].get());
    }

    const Player& Model::getAttackingPlayer() const {
        return *(players[playerTurn].get());
    }

    Player& Model::getDefendingPlayer(){
        return *(players[playerTurn].get());
    }

    const Player& Model::getDefendingPlayer() const{
            return *(players[playerTurn].get());
    }

    bool Model::isGameOver(){
        for(int i = 0; i<2; i++){
            if(players[i].get()->allShipsSunk()){
                forcedGameOver = true;
            }
        }
        return forcedGameOver;
    }

    void Model::changeTurn(){
        playerTurn = playerTurn == 0? 1:0;
    }

    void Model::loadGameConfigurationFromFile(const std::string &gameConfigurationFile){
        std::ifstream myfile(gameConfigurationFile);
        if(myfile){
            int row, col;
            myfile>>row; myfile>>col;
            gameAttributes = GameAttributes(row, col);
        }
        int numShip = 0;
        myfile>>numShip;
        for(int i = 0; i<numShip; i++) {
            char shipChar;
            int shipSize;
            myfile>>shipChar; myfile>>shipSize;
            gameAttributes.setShipAttribute(shipChar, shipSize);
        }
        myfile.close();
    }

    void Model::endGame(){

    }
    std::unique_ptr<Move> Model::getNextMove(){
        return getAttackingPlayer().getMove();
    }

    Player& Model::getWinner(){
        if(players[0]->allShipsSunk()){
            return *players[1].get();
        }else{
            return *players[0].get();
        }
    }

    void Model::SetOpponents(){
        players[0].get()->setOpponent(*players[1].get());
        players[1].get()->setOpponent(*players[0].get());
    }


}
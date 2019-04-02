//
// Created by mfbut on 3/9/2019.
//

#include "Player.h"

namespace BattleShip {
    int Player::num_instances = 0;

    Player::Player(const GameAttributes &gameAttributes, View &view): id(++num_instances),
    view(view), /*shipHealths(gameAttributes.getShipAttributes()),*/
    board(Board(gameAttributes.getNumRows(), gameAttributes.getNumCols())){
        shipHealths = gameAttributes.getShipAttributes();
    }

    const std::string & Player::getName() const{
        return name;
    }

    void Player::setName(const std::string &Name){
        name = Name;
    }

    const Board& Player::getBoard() const{
        return board;
    }

    Board& Player::getBoard(){
        return board;
    }

    const int Player::getId() const{
        return id;
    }

//for hashing
    bool Player::operator==(const Player &rhs) const{
        return id == rhs.getId();
    }

    bool Player::operator!=(const Player &rhs) const{
        return !(operator==(rhs));
    }


    bool Player::allShipsSunk() const{
        for(auto& x : shipHealths){
            if (x.second != 0){
                return false;
            }
        }
        return true;
    }

    //change the data after being attacked and also return the result.
    AttackResult Player::firedAt(int row, int col){
        board.at(row,col).setHasBeenFiredAt(true);
        char fired = board.at(row, col).getContents();
        bool hit = board.at(row, col).containsShip();
        bool destroyed = false;
        if(hit) {
           shipHealths.at(fired)--;
           if (shipHealths.at(fired)==0){
               destroyed = true;
           }
        }
        return {hit, destroyed, fired};

    }

    Player& Player::getOpponent(){
        return *opponent;
    }

    const Player& Player::getOpponent() const{
        return *opponent;
    }

    void Player::setOpponent(Player& Opponent){
        opponent = &Opponent;
    }

    Player::~Player(){};
    //bool Player::hit(char shipChar){

    //}
}
//
// Created by mfbut on 3/9/2019.
//

#include <algorithm>
#include <vector>
#include <cctype>
#include "StandardView.h"
#include "Utility.h"

using namespace BattleShip;

StandardView::StandardView() : in(std::cin), out(std::cout){}
StandardView::StandardView(std::istream& in, std::ostream& out) : in(in), out(out){
}

PlayerConfiguration StandardView::getPlayerConfiguration(){
    out<<"What type of game do you want to play?\n1. Human vs Human\n2. Human vs AI\n3. AI vs AI\nYour choice: ";
    int a;
    verifiedRead(in, a);
    if(a == 1){
        return PlayerConfiguration(2, 0);
    }if(a==2){
        return PlayerConfiguration(1, 1);
    }else{
        return PlayerConfiguration(0, 2);
    }
}

std::string StandardView::getPlayerName(int i){
    out<< "Player " + std::to_string(i) + " please enter your name: ";
    std::string a;
    in>>a;
    return a;
}

ShipPlacement StandardView::getShipPlacement(const Player& player, char shipChar, int shipLen){
    char c;
    //rowstart and colstart.etc
    int srow, scol, erow, ecol;
    do {
        out << player.getName() + ", do you want to place " + shipChar + " horizontally or vertically?\n" +
               "Enter h for horizontal or v for vertical\nYour choice: ";
        in >> c;
    }while(c!='h' && c!= 'H'&& c!= 'v'&& c!='V');

    out << player.getName() + ", enter the row and column you want to place " + shipChar + ", which is " +
               std::to_string(shipLen) + " long, at with a space in between row and col: ";
    in >> srow >> scol;
    if (c == 'h' || c == 'H'){
        erow = srow;
        ecol = scol+shipLen-1;
        return ShipPlacement(srow, scol, erow, ecol);
    }else{
        erow = srow+shipLen-1;
        ecol = scol;
        return ShipPlacement(srow, scol, erow, ecol);
    }
}

void StandardView::updateShipPlacementView(const Player& player){

}

std::pair<int, int> StandardView::getFiringCoordinate(const BattleShip::Player& attacker){
    showPlayersBoard(attacker);
    out<<attacker.getName() + ", where would you like to fire?\nEnter your attack coordinate in the form row col: ";
    int a,b;
    in>>a>>b;
    return {a,b};
}
void StandardView::showWinner(const Player& winner){
    out<< winner.getName() + " won the game!";
}

void StandardView::showResultOfAttack(const BattleShip::Player& attacker, const BattleShip::AttackResult& attackResult){
    showPlayersBoard(attacker);
    if(attackResult.hit){
        out<<attacker.getName() + " hit " + attacker.getOpponent().getName() + "'s " + attackResult.shipChar + "!\n";
    }else{
        out<< "Missed.\n";
    }
    if(attackResult.destroyed){
        out<<attacker.getName() + " destroyed " + attacker.getOpponent().getName() + "'s " + attackResult.shipChar + "!\n";
    }
    out<<"\n";
}

void StandardView::showPlayersBoard(const Player& player){
    out<<player.getName() + "'s Firing Board\n";
    printBoardAsObscured(player.getOpponent().getBoard());
    out<<"\n\n";
    out<<player.getName() + "'s Placement Board\n";
    printBoardAsVisible(player.getBoard());

}
void StandardView::showPlacementBoard(const Player& player){
    printBoardAsVisible(player.getBoard());
}

void StandardView::printBoard(const std::vector<std::string>& board){
    for(auto& s: board){
        out<<s;
    }
}
void StandardView::printBoardAsVisible(const Board& board){
    printBoard(board.getVisibleVersion());
}
void StandardView::printBoardAsObscured(const Board& board){
    printBoard(board.getHiddenVersion());
}

int StandardView::getAiChoice(){
    out<<"What AI do you want?\n1. Cheating AI\n2. Random AI\n3. Hunt Destroy AI\nYour choice: ";
    int a;
    verifiedRead(in, a);
    return a;
}

void clearInput(){}


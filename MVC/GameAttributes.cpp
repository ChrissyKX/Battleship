//
// Created by mfbut on 3/9/2019.
//
#include <utility>
#include "Utility.h"
#include "GameAttributes.h"

namespace BattleShip {

    GameAttributes::GameAttributes() : GameAttributes(10, 10) {
        shipAttributes['B'] = 4;
        shipAttributes['C'] = 5;
        shipAttributes['D'] = 3;
        shipAttributes['S'] = 3;
        shipAttributes['P'] = 2;
    }

    GameAttributes::GameAttributes(int numRows, int numCols) : numRows(numRows), numCols(numCols) {

    }

    GameAttributes::GameAttributes(std::istream &in) {
        char shipChar;
        int numship, shipSize;
        in >> numRows;
        in >> numCols;
        in >> numship;
        for (int i = 0; i < numship; ++i) {
            in >> shipChar >> shipSize;
            shipAttributes[shipChar] = shipSize;
        }
    }

    int GameAttributes::getNumRows() const {
        return numRows;
    }

    void GameAttributes::setNumRows(int numRow) {
        numRows = numRow;
    }

    int GameAttributes::getNumCols() const {
        return numCols;
    }

    void GameAttributes::setNumCols(int numCol) {
        numCols = numCol;
    }

    int GameAttributes::getShipSize(const char ShipChar) const {
        return shipAttributes.at(ShipChar);
    }

    const std::map<char, int> &GameAttributes::getShipAttributes() const {
        return shipAttributes;
    }


    void GameAttributes::setShipAttribute(char shipChar, int shipSize){
       this->shipAttributes.insert(std::pair<char, int>(shipChar, shipSize));
    }
    /*std::istream &operator>>(std::istream &in, GameAttributes &gameAttributes) {
        gameAttributes = GameAttributes(in);
        return in;
    }*/

}
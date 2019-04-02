//
// Created by mfbut on 3/10/2019.
//

#include "Board.h"
#include <iostream>
namespace BattleShip {
    Board::Board(int numRows, int numCols, char blankChar):numrow(numRows),numcol(numCols), blankChar(blankChar){
        for(int i = 0; i<numRows; ++i){
            boardState.push_back(std::vector<Cell>(numCols, Cell(blankChar)));
        }
    }

    Board::Board(int numRows, int numCols) : Board(numRows,numCols,'*'){
    }

    bool Board::canPlaceShipAt(const ShipPlacement &shipPlacement) const{
        return inBounds(shipPlacement) && spacesAreEmpty(shipPlacement);
    }

    int Board::getNumRows() const{
        return numrow;
    }

    int Board::getNumCols() const{
        return numcol;
    }

    std::vector<std::string> Board::getHiddenVersion() const{
        std::vector<std::string> result;
        std::string temp = " ";
        for (int i = 0; i<numcol; ++i){
            temp += " "+ std::to_string(i);
        }
        result.push_back(temp + "\n");
        for (int i = 0; i<numrow; ++i){
            temp = std::to_string(i);
            for (int k = 0; k<numcol; ++k) {
                temp += " ";
                temp += boardState[i][k].getContentsIfHidden();
            }
            result.push_back(temp + "\n");
        }
        return result;
    }

    std::vector<std::string> Board::getVisibleVersion() const{
        std::vector<std::string> result;
        std::string temp = " ";
        for (int i = 0; i<numcol; ++i){
            temp += " "+ std::to_string(i);
        }
        result.push_back(temp + "\n");
        for (int i = 0; i<numrow; ++i){
            temp = std::to_string(i);
            for (int k = 0; k<numcol; ++k) {
                temp += " ";
                temp += boardState[i][k].getContentsIfVisible();
            }
            result.push_back(temp + "\n");
        }
        return result;
    }

    void Board::AddShip(char shipChar, const ShipPlacement &shipPlacement){
        if (canPlaceShipAt(shipPlacement)){
            for(int i = shipPlacement.rowStart; i<=shipPlacement.rowEnd; ++i){
                for (int k = shipPlacement.colStart; k<=shipPlacement.colEnd; ++k){
                    boardState[i][k].setContents(shipChar);
                }
            }
        }
    }

    bool Board::inBounds(int row, int col) const{
        return between(row, 0, numrow) && between(col, 0, numcol);
    }

    Cell & Board::at(int i, int j){
        return boardState[i][j];
    }

    const Cell & Board::at(int i, int j) const{
        return boardState[i][j];
    }

    bool Board::inBounds(const ShipPlacement &shipPlacement) const{
        return inBounds(shipPlacement.rowStart, shipPlacement.colStart) && inBounds(shipPlacement.rowEnd, shipPlacement.colEnd);
    }

    bool Board::between(int value, int low, int high) const{
        return value>=low && value < high;
    }

    bool Board::spacesAreEmpty(const ShipPlacement &shipPlacement) const{
        for(int i = shipPlacement.rowStart; i<=shipPlacement.rowEnd; ++i){
            for (int k = shipPlacement.colStart; k<=shipPlacement.colEnd; ++k){
                if(boardState[i][k].getContents() != blankChar){
                    return false;
                }
            }
        }
        return true;
    }
}
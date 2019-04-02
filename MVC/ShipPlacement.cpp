//
// Created by mfbut on 3/10/2019.
//

#include <algorithm>
#include "ShipPlacement.h"

using namespace BattleShip;

ShipPlacement::ShipPlacement(){

}
ShipPlacement::ShipPlacement(int rowStart, int colStart, int rowEnd, int colEnd): rowStart(rowStart), colStart(colStart), rowEnd(rowEnd), colEnd(colEnd){
}
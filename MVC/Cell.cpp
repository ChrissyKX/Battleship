//
// Created by mfbut on 3/10/2019.
//

#include <stdexcept>
#include "Cell.h"

namespace BattleShip {
    Cell::Cell(char contents, const char hiddenMarker, const char hitMarker, const char missMarker) : contents(contents),
    hiddenMarker(hiddenMarker), hitMarker(hitMarker), missMarker(missMarker){

    }

    Cell::Cell(char contents) : contents(contents), hiddenMarker('*'), hitMarker('X'), missMarker('O'){
    }

    char Cell::getContents() const{
        return contents;
    }

    void Cell::setContents(char content){
        contents = content;
    }

    char Cell::getContentsIfHidden() const{
        if (firedAt ){
            if(containsShip()){
                return hitMarker;
            }else{
                return missMarker;
            }
        }else{
            return hiddenMarker;
        }
    }

    char Cell::getContentsIfVisible() const{
        if (firedAt ){
            if(containsShip()){
                return hitMarker;
            }else{
                return missMarker;
            }
        }else{
            return contents;
        }
    }

    bool Cell::HasBeenFiredAt() const{
        return firedAt;
    }

    void Cell::setHasBeenFiredAt(bool hasBeenFiredAt){
        firedAt = hasBeenFiredAt;
    }

    bool Cell::containsShip() const{
        return contents!= hiddenMarker;

    }
}
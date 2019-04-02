//
// Created by mfbut on 3/9/2019.
//

#include <stdexcept>
#include <vector>
#include <sstream>
#include "PlayerConfiguration.h"
#include "Controller.h"
#include "HumanPlayer.h"
#include "AiPlayer.h"
#include "StandardView.h"
#include "CheatingAI.h"
#include "RandomAI.h"
#include "HuntDestroyAI.h"

namespace BattleShip {
        Controller::Controller(){
            hasBeenSetUp = false;
            model = Model();
            view = std::make_unique<StandardView>(StandardView());
        }
        void Controller::setupGame(const std::string& GameConfigurationFile, int seed){
             AiPlayer::seed_random_number_generator(seed);
             setupGame(GameConfigurationFile);
        }

        void Controller::setupGame(const std::string& GameConfigurationFile){
            model.loadGameConfigurationFromFile(GameConfigurationFile);
            setupGame();
        }
        void Controller::setupGame(){
            auto pc = view->getPlayerConfiguration();
            for(int i = 0;i < pc.numHumanPlayers; i++){
                model.addPlayer<HumanPlayer>(*view);
            }
            int choice;
            for(int i = 0; i< pc.numAiPlayers; i++){
                choice = view->getAiChoice();
                if(choice == 1){
                    model.addPlayer<CheatingAI>(*view);
                }else if(choice == 2){
                    model.addPlayer<RandomAI>(*view);
                }else if(choice == 3){
                    model.addPlayer<HuntDestroyAI>(*view);
                }
            }
            model.SetOpponents();
        }

        void Controller::playGame(){
            while (!model.isGameOver()){
                auto attack = model.getNextMove();
                if(attack->isValid()) {
                    attack->enact(model, *view);
                }
            }
            view->showWinner(model.getWinner());
        }



}
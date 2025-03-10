//
// Created by JoachimWagner on 10.03.2025.
//

#pragma once
#include "../Game.h"
namespace atlas::game::nimgame {

    class NimGame: public Game {
    public:
        NimGame():_stones{23} {}

        auto play()->void override {
            while(! isGameOver()) {
                playRound();
            }
        }
    private:
        auto playRound()-> void { // Integration
            humanTurn();
            computerTurn();
        }
        auto humanTurn()->void{
            if(isGameOver()) return;

            while(true) {
                std::cout << "Es gibt " << _stones << " Steine. Bitte nehmen Sie 1,2 oder 3!" << std::endl;
                std::cin >> _turn;
                if(_turn >= 1 && _turn <=3) break;
                std::cout << " Ungueltiger Zug" << std::endl;
            }
            terminateTurn( "Mensch");
        }
        auto computerTurn()->void{
            if(isGameOver()) return;
            const int turns[] = {3,1,1,2};


            _turn = turns[_stones % 4];
            std::cout << "Computer nimmt" << _turn << " Steine." << std::endl;
            terminateTurn( "Computer");

        }

        auto terminateTurn(std::string player) -> void {
            updateBoard();
            printGameOverMessageIfGameIsOver(player);
        }

        auto printGameOverMessageIfGameIsOver(const std::string &player) -> void {
            if(isGameOver()) {
                std::cout << player  << " hat verloren." << std::endl;
            }
        }

        // ------------------- Implementierungssumpf

        auto updateBoard()-> void { _stones -= _turn; }

        auto isGameOver()->bool { // Operation
            return _stones < 1;
        }

        int _stones;
        int _turn;
        bool _gameover;
    };




}

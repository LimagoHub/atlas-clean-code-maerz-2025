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

        auto playRound()-> void {
            humanTurn();
            computerTurn();
        }
        auto humanTurn()->void{
            int turn;
            while(true) {
                std::cout << "Es gibt " << _stones << " Steine. Bitte nehmen Sie 1,2 oder 3!" << std::endl;
                std::cin >> turn;
                if(turn >= 1 && turn <=3) break;
                std::cout << " Ungueltiger Zug" << std::endl;
            }
            _stones -= turn;
        }


        auto computerTurn()->void{
            const int turns[] = {3,1,1,2};
            if(isGameOver()) {
                std::cout << " Du Loser" << std::endl;
                return;
            }
            if(_stones == 1) {
                std::cout << " Du hast nur Glueck gehabt" << std::endl;
                _stones = 0;
                return;
            }
            const int turn = turns[_stones % 4];
            std::cout << "Computer nimmt" << turn << " Steine." << std::endl;
            _stones -= turn;
        }

        auto isGameOver()->bool {
            return _stones < 1;
        }

        int _stones;
        bool _gameover;
    };




}

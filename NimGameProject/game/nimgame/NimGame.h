//
// Created by JoachimWagner on 10.03.2025.
//

#pragma once
#include "../Game.h"
namespace atlas::game::nimgame {

    class NimGame: public Game {
    public:
        NimGame():_stones{23}, _gameover{false} {}

        auto play()->void override {
            while(! _gameover) {
                humanTurn();
                computerTurn();
            }
        }


    private:

        auto humanTurn()->void{}
        auto computerTurn()->void{}

        int _stones;
        bool _gameover;
    };




}

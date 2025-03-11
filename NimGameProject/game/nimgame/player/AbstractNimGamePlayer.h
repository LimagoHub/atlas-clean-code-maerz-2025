//
// Created by JoachimWagner on 11.03.2025.
//

#pragma once

#include <string>
#include "NimGamePlayer.h"
namespace atlas::game::nimgame::player {

    class AbstractNimGamePlayer: public NimGamePlayer{

    public:
        explicit AbstractNimGamePlayer(const std::string &name) : name(name) {}

        const std::string getName() const override{
            return name;
        }

    private:
        std::string name;

    };

}

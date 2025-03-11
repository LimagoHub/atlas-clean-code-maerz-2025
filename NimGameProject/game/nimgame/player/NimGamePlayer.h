//
// Created by JoachimWagner on 11.03.2025.
//

#pragma once

#include <string>

namespace atlas::game::nimgame::player {
    class NimGamePlayer {
    public:
        virtual ~NimGamePlayer() = default;
        virtual auto getName() const -> const std::string = 0;
        virtual auto doTurn(const int stones) const -> int = 0;
    };
}

//
// Created by JoachimWagner on 12.03.2025.
//

#pragma once

#include <iostream>

namespace atlas::bootstrap {
    class Bootstrap {
    public:
        virtual ~Bootstrap() = default;

        auto run()-> void {
            std::cout << "Starte App" << std::endl;
        }
    };
}

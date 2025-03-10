#include <iostream>
#include "game/nimgame/NimGame.h"
#include "client/GameClient.h"
using namespace atlas;
int main() {

    game::nimgame::NimGame game;
    client::GameClient client{game};
    client.go();

    return 0;
}


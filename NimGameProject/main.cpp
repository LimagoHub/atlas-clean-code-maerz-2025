#include <iostream>
#include "game/nimgame/NimGame.h"
#include "client/GameClient.h"
#include "io/ConsoleWriter.h"
#include "game/nimgame/player/HumanPlayer.h"
#include "game/nimgame/player/ComputerPlayer.h"
using namespace atlas;
int main() {

    atlas::io::ConsoleWriter writer;
    atlas::game::nimgame::player::HumanPlayer human{"Fritz"};
    atlas::game::nimgame::player::ComputerPlayer computer{"Computer"};
    game::nimgame::NimGame game{writer};
    game.addPlayer(&human);
    game.addPlayer(&computer);
    client::GameClient client{game};
    client.go();

    return 0;
}


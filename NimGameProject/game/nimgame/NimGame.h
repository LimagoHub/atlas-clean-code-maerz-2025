//
// Created by JoachimWagner on 10.03.2025.
//

#pragma once
#include <vector>
#include "../Game.h"
#include "../../io/Writer.h"
#include "player/NimGamePlayer.h"
namespace atlas::game::nimgame {

    class NimGame: public Game {
        using PLAYER = player::NimGamePlayer *;
        using PLAYERS = std::vector<PLAYER>;

    public:
        explicit NimGame(io::Writer &writer) : writer(writer), _stones{23} {}

        auto addPlayer(PLAYER player) -> void {
            players.push_back(player);
        }
        auto removePlayer(PLAYER player) -> void {
            // Not implemented yet
        }

        auto play()->void override {
            while(! isGameOver()) {
                playRound();
            }
        }



    private:
        auto playRound()-> void { // Integration

           for(auto player: players) {
               setCurrentPlayer(player);
               playSingleTurn();
           }


        }

        auto playSingleTurn()->void{
            if(isGameOver()) return;
            executeTurn();
            terminateTurn();
        }

        auto executeTurn()->void {
            do {
                _turn = getCurrentPlayer()->doTurn(_stones);
            } while(turnIsNotValid());
        }

        auto turnIsNotValid()-> bool {
            if( isTurnValid()) return false;
            write("Ungueltiger Zug");
            return true;
        }


        auto terminateTurn() -> void {
            updateBoard();
            printGameOverMessageIfGameIsOver();
        }

        auto printGameOverMessageIfGameIsOver() -> void {
            if(isGameOver()) {
                   write(getCurrentPlayer()->getName() + " hat verloren.");
            }
        }

        // ------------------- Implementierungssumpf

        auto updateBoard()-> void { _stones -= _turn; }

        auto isGameOver()->bool { // Operation
            return _stones < 1 || players.empty();
        }

        auto isTurnValid() const -> bool { return _turn >= 1 && _turn <= 3; }

        PLAYERS players;
        PLAYER currentPlayer;
        atlas::io::Writer &writer;
        int _stones;
        int _turn;
        bool _gameover;
    protected:

        const PLAYER getCurrentPlayer() const {
            return currentPlayer;
        }

        void setCurrentPlayer(const PLAYER currentPlayer) {
            NimGame::currentPlayer = currentPlayer;
        }

        auto write(std::string message)->void {
            writer.write(message);
        }
    };




}

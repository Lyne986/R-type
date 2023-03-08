#include "GameLogic/Game.hpp"

namespace RT::Server::GameLogic {

    Game::Game()
    {
    }

    void Game::update()
    {
        this->partyManager->update();
    }

}

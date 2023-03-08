#ifndef __RT_SERVER_GAME_LOGIC_GAME_HPP__
    #define __RT_SERVER_GAME_LOGIC_GAME_HPP__
 
    #include "GameLogicNamespace.hpp"
    #include "GameLogic/PartyManager.hpp"
    #include <GameEngineECS.hpp>
    #include <memory>

namespace RT::Server::GameLogic {
    class Game {
        private:
            std::shared_ptr<PartyManager> partyManager = PartyManager::getInstance();

        public:
            void update();
            Game();
    };
}

#endif
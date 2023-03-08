#ifndef __RT_SERVER_GAMELOGIC_PARTYMANAGER_HPP__
    #define __RT_SERVER_GAMELOGIC_PARTYMANAGER_HPP__

    #include "GameLogicNamespace.hpp"
    #include "GameLogic/Party.hpp"
    #include <vector>
    #include <memory>
    #include <unordered_map>

namespace RT::Server::GameLogic {

    class PartyManager {
        private:
            int lastId = 0;
            std::unordered_map<int, std::shared_ptr<Party>> parties = {};

        public:
            PartyManager();
            void removeParty(int pid);
            void update();
            void joinParty(int id, std::shared_ptr<Connection<CustomMsgTypes>> client);
            void setPosition(int id, int pid, GE::Utils::Vector2<int> position);
            void shoot(int id, int pid, GE::Utils::Vector2<int> position);
            void shoot(int pid, int id);
            void disconnect(int id, int pid);
            void disconnect(std::shared_ptr<Connection<CustomMsgTypes>> client);
            std::shared_ptr<Party> getParty(int pid);
            static std::shared_ptr<PartyManager> getInstance();
    };

}

#endif
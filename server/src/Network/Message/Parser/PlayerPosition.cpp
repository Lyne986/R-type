#include "Network/Message/Parser/PlayerPosition.hpp"

namespace RT::Server::Network::Message::Parser {
    PlayerPosition::PlayerPosition(MyServer &server) : AParser(server) {}

    void PlayerPosition::parse(std::shared_ptr<Connection<CustomMsgTypes>>, message_s<CustomMsgTypes>& msg)
    {
        GE::Network::Message::PlayerPosition playerPosition;

        msg >> playerPosition;
        // std::cout << "received " << playerPosition.pid << " " << playerPosition.x << " " << playerPosition.y << std::endl;
        this->partyManager->setPosition(playerPosition.gid, playerPosition.pid, GE::Utils::Vector2<int>(playerPosition.x, playerPosition.y));
    }
}
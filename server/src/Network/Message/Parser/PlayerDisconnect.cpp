#include "Network/Message/Parser/PlayerDisconnect.hpp"

namespace RT::Server::Network::Message::Parser {

    PlayerDisconnect::PlayerDisconnect(MyServer &server) : AParser(server) {}

    void PlayerDisconnect::parse(std::shared_ptr<Connection<CustomMsgTypes>>, message_s<CustomMsgTypes>& msg) {
        GE::Network::Message::PlayerDisconnect playerDisconnect;
        msg >> playerDisconnect;
        this->partyManager->disconnect(1, playerDisconnect.pid);
    }
}
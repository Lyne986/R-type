#include "JoinMessage.hpp"

namespace RT::Server::Network::Message::Parser {

    JoinMessage::JoinMessage(MyServer &server) : AParser(server) {}

    void JoinMessage::parse(std::shared_ptr<Connection<CustomMsgTypes>> client, message_s<CustomMsgTypes>& msg) {
        GE::Network::Message::JoinMessage joinMessage;
        msg >> joinMessage;

        this->partyManager->joinParty(joinMessage.party, client);
    }

}
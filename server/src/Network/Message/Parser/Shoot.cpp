#include "Shoot.hpp"

namespace RT::Server::Network::Message::Parser {
    Shoot::Shoot(MyServer &server)
    : AParser(server) {}

    void Shoot::parse(std::shared_ptr<Connection<CustomMsgTypes>> client, message_s<CustomMsgTypes>& msg)
    {
        RT::GE::Network::Message::Shoot_s shoot;
        msg >> shoot;
        std::cout << "Shoot received from " << shoot.pid << " " << shoot.id << std::endl;
        this->partyManager->shoot(shoot.pid, shoot.id);
    }
}
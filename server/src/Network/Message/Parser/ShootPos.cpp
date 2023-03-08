#include "Network/Message/Parser/ShootPos.hpp"

namespace RT::Server::Network::Message::Parser {

    ShootPos::ShootPos(MyServer &server): AParser(server) {}

    void ShootPos::parse(std::shared_ptr<Connection<CustomMsgTypes>>, message_s<CustomMsgTypes>& msg)
    {
        GE::Network::Message::ShootPos shoot;
        msg >> shoot;
        int pid = shoot.pid;
        GE::Utils::Vector2<int> pos(shoot.x, shoot.y);
        this->partyManager->shoot(shoot.gid, pid, pos);
    }
}
#include "GameLogic/Party.hpp"

namespace RT::Server::GameLogic {

    Party::Party() {
        this->spawnManager = std::make_shared<SpawnManager>("assets/objects/data/level1.json");
        std::cout << "Party created" << std::endl;
    }

    void Party::addPlayer(std::shared_ptr<Connection<CustomMsgTypes>> client)
    {
        auto condition = std::find_if(this->client.begin(), this->client.end(), [client](auto &c) {
            return (c.second->GetID() == client->GetID());
        });
        if (condition == this->client.end()) {
            std::cout << "Adding player " << client->GetID() << std::endl;
            this->client.insert({this->curr_pid, client});
            message_s<CustomMsgTypes> msg("Join");
            msg.header.id = CustomMsgTypes::ServerMessage;
            RT::GE::Network::Message::JoinMessage joinMessageRes(this->curr_pid);
            msg << joinMessageRes;
            client->Send(msg);
            this->spawnManager->addPlayer(client, this->curr_pid);
            this->sendToAllPlayers(this->curr_pid);
            this->curr_pid++;
        }
    }

    void Party::sendToAllPlayers(int pid)
    {
        for (auto &c : this->client) {
            if (c.first != pid) {
                message_s<CustomMsgTypes> msg("PlayerJoin");
                msg.header.id = CustomMsgTypes::ServerMessage;
                RT::GE::Network::Message::PlayerJoin playerJoin(pid);
                msg << playerJoin;
                this->client[c.first]->Send(msg);
            } else {
                for (auto &c2 : this->client) {
                    if (c2.first != pid) {
                        message_s<CustomMsgTypes> msg("PlayerJoin");
                        msg.header.id = CustomMsgTypes::ServerMessage;
                        RT::GE::Network::Message::PlayerJoin playerJoin(c2.first);
                        msg << playerJoin;
                        this->client[pid]->Send(msg);
                    }
                }
            }
        }
    }

    void Party::setPosition(int pid, GE::Utils::Vector2<int> position)
    {
        this->playerPosition[pid] = position;
        for (auto &c : this->client) {
            // if (c.first != pid) {
                message_s<CustomMsgTypes> msg("PlayerPosition");
                msg.header.id = CustomMsgTypes::ServerMessage;
                RT::GE::Network::Message::PlayerPosition playerPosition(pid, position.x, position.y);
                msg << playerPosition;
                // std::cout << "Sending position to " << c.first << std::endl;
                // std::cout << "Sent position to " << this->client[c.first]->_udp_remoteEndpoint.address().to_string() << " " << this->client[c.first]->_udp_remoteEndpoint.port() << std::endl;
                this->client[c.first]->SendUDP(msg);
            // }
        }
    }

    void Party::shoot(int pid, GE::Utils::Vector2<int> pos)
    {
        for (auto &c : this->client) {
            if (c.first != pid) {
                message_s<CustomMsgTypes> msg("ShootPos");
                msg.header.id = CustomMsgTypes::ServerMessage;
                RT::GE::Network::Message::ShootPos playerShoot(pid, pos.x, pos.y);
                msg << playerShoot;
                this->client[c.first]->SendUDP(msg);
            }
        }
    }

    void Party::shoot(int id)
    {
        GE::Network::Message::Shoot shoot(0, id);
        message_s<CustomMsgTypes> msg("Shoot");
        msg.header.id = CustomMsgTypes::ServerMessage;
        msg << shoot;

        for (auto &c : this->client) {
            if (c.first != id) {
                c.second->Send(msg);
            }
        }
    }

    void Party::disconnect(int pid)
    {
        this->client.erase(pid);
        this->playerPosition.erase(pid);
        this->curr_pid--;
        for (auto &c : this->client) {
            message_s<CustomMsgTypes> msg("PlayerDisconnect");
            msg.header.id = CustomMsgTypes::ServerMessage;
            RT::GE::Network::Message::PlayerDisconnect playerDisconnect(pid);
            msg << playerDisconnect;
            this->client[c.first]->Send(msg);
        }
    }

    void Party::disconnect(std::shared_ptr<Connection<CustomMsgTypes>> client) {
        auto condition = std::find_if(this->client.begin(), this->client.end(), [client](auto &c) {
            return (c.second->GetID() == client->GetID());
        });
        std::cout << "IN" << std::endl;
        if (condition != this->client.end()) {
            std::cout << "Disconnecting player " << client->GetID() << std::endl;
            int pid = condition->first;
            GE::Network::Message::PlayerDisconnect disconnect(pid);
            message_s<CustomMsgTypes> msg("PlayerDisconnect");
            msg.header.id = CustomMsgTypes::ServerMessage;
            msg << disconnect;
            for (auto &c : this->client) {
                if (c.first != pid) {
                    c.second->Send(msg);
                }
            }
            this->client.erase(pid);
            this->playerPosition.erase(pid);
        }
    }

    void Party::update()
    {
        if (this->spawnManager != nullptr) {
            this->spawnManager->update();
        }
    }

}

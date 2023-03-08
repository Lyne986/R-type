#include "GameLogic/PartyManager.hpp"

namespace RT::Server::GameLogic
{

    PartyManager::PartyManager()
    {
    }

    void PartyManager::removeParty(int pid)
    {
        this->parties.erase(pid);
    }

    std::shared_ptr<Party> PartyManager::getParty(int pid)
    {
        return this->parties[pid];
    }

    std::shared_ptr<PartyManager> PartyManager::getInstance()
    {
        static std::shared_ptr<PartyManager> instance = std::make_shared<PartyManager>();

        return instance;
    }

    void PartyManager::update()
    {
        for (auto it : this->parties) {
            if (it.second) {
                it.second->update();
            }
        }
    }

    void PartyManager::shoot(int pid, int id)
    {
        this->parties[pid]->shoot(id);
    }

    void PartyManager::joinParty(int id, std::shared_ptr<Connection<CustomMsgTypes>> client)
    {
        if (this->parties.find(id) == this->parties.end()) {
            std::cout << "Creating new party " << id << std::endl;
            this->parties[id] = std::make_shared<Party>();
        }
        this->parties[id]->addPlayer(client);
    }

    void PartyManager::setPosition(int id, int pid, GE::Utils::Vector2<int> position)
    {
        if (this->parties.find(id) != this->parties.end()) {
            this->parties[id]->setPosition(pid, position);
        }
    }

    void PartyManager::shoot(int id, int pid, GE::Utils::Vector2<int> position)
    {
        if (this->parties.find(id) != this->parties.end()) {
            this->parties[id]->shoot(pid, position);
        }
    }

    void PartyManager::disconnect(int id, int pid)
    {
        if (this->parties.find(id) != this->parties.end()) {
            this->parties[id]->disconnect(pid);
        }
    }

    void PartyManager::disconnect(std::shared_ptr<Connection<CustomMsgTypes>> client)
    {
        for (auto it : this->parties) {
            if (it.second) {
                it.second->disconnect(client);
            }
        }
    }
}

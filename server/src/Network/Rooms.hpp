/*
** EPITECH PROJECT, 2022
** rtype
** File description:
** Rooms
*/

#ifndef ROOMS_HPP_
#define ROOMS_HPP_

#include <memory>
#include <vector>
#include <functional>
#include <string>
#include <GameEngineNetwork.hpp>

namespace RT::Server::Network {
    class Rooms {
        public:
            Rooms(std::shared_ptr<Connection<CustomMsgTypes>> client, int id, std::string name = "default")
            {
                std::cout << "New Room is created" << std::endl;
                _clients.push_back(client);
                _name = name;
                _id = id;
            }

            ~Rooms()
            {
            }

            bool addClient(std::shared_ptr<Connection<CustomMsgTypes>> client)
            {
                if (client == nullptr && _clients.size() >= 4)
                    return false;
                for (std::shared_ptr<Connection<CustomMsgTypes>> &c : _clients) {
                    if (c == client)
                        return false;
                }
                _clients.push_back(client);

                return true;
            }

            void removeClient(std::shared_ptr<Connection<CustomMsgTypes>> client)
            {
                _clients.erase(std::remove(_clients.begin(), _clients.end(), client), _clients.end());
            }

            void setName(std::string name)
            {
                _name = name;
            }

            std::string getName() const
            {
                return _name;
            }

            std::vector<std::shared_ptr<Connection<CustomMsgTypes>>> getClients() const
            {
                return _clients;
            }

            int getId() const
            {
                return _id;
            }

            int getNbClients() const
            {
                return _clients.size();
            }

        private:
            std::vector<std::shared_ptr<Connection<CustomMsgTypes>>> _clients;
            std::string _name;
            int _id;
    };
}
#endif /* !ROOMS_HPP_ */

#ifndef __RT_CLIENT_NETWORK_SYSTEM_OTHERCLIENT_HPP__
    #define __RT_CLIENT_NETWORK_SYSTEM_OTHERCLIENT_HPP__

    #include <GameEngineECS.hpp>
    #include <GameEngineNetwork.hpp>
    #include "ClientNamespace.hpp"
    #include "Components/OnlinePlayer.hpp"
    #include "Network/SingletonClient.hpp"

namespace RT::Client::Systems {
    class OnlinePlayer : public GE::ECS::Systems::ASystem {
        private:
            std::shared_ptr<GE::Network::Client::Client> client = RT::Client::Network::SingletonClient::getInstance();
            bool isConnected = false;

            void updateConnection();
            void updateUnconnected();
            void updateConnected();

        public:
            void init(std::shared_ptr<GE::ECS::EntityManager> entityManager);
            void update(std::shared_ptr<GE::ECS::EntityManager> entityManager);
    };
}

#endif
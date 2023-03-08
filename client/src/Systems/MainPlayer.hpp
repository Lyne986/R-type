#ifndef __RT_CLIENT_SYSTEMS_MAINPLAYER_HPP__
    #define __RT_CLIENT_SYSTEMS_MAINPLAYER_HPP__

    #include <GameEngineECS.hpp>
    #include <GameEngineUtils.hpp>
    #include <GameEngineNetwork.hpp>
    #include <memory>
    #include "Network/SingletonClient.hpp"
    #include "ClientNamespace.hpp"
    #include "Components/MainPlayer.hpp"
    #include "Components/SingletonIdRoom.hpp"

namespace RT::Client::Systems {

    class MainPlayer : public GE::ECS::Systems::ASystem {
        private:
            std::shared_ptr<GE::Network::Client::Client> client = Network::SingletonClient::getInstance();
            int pid = 0;
            std::shared_ptr<SingletonIdRoom> _IdInstance = SingletonIdRoom::getInstance();

        public:
            MainPlayer();
            ~MainPlayer();
            void init(std::shared_ptr<GE::ECS::EntityManager> entityManager);
            void update(std::shared_ptr<GE::ECS::EntityManager> entityManager);
            void updateUnConnected();
            void updateConnected(GE::ECS::Entity entity, GE::ECS::ComponentManager &componentManager);
    };


}

#endif
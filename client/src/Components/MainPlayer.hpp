#ifndef __RT_CLIENT_COMPONENTS_MAINPLAYER_HPP__
    #define __RT_CLIENT_COMPONENTS_MAINPLAYER_HPP__

    #include <GameEngineECS.hpp>
    #include <memory>
    #include "ClientNamespace.hpp"
    #include "Network/SingletonClient.hpp"

namespace RT::Client::Components {
    class MainPlayer : public GE::ECS::Components::AComponent {
        private:
            std::shared_ptr<GE::Network::Client::Client> client = Network::SingletonClient::getInstance();
            bool connected = false;
            int pid = -1;

        public:
            bool isConnected() const;
            void isConnected(bool connected);
            void setPid(int pid);
            int getPid() const;
    };
}

#endif
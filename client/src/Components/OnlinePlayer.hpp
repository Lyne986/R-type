#ifndef __RT_CLIENT_COMPONENT_ONLINEPLAYER_HPP__
    #define __RT_CLIENT_COMPONENT_ONLINEPLAYER_HPP__

    #include <GameEngineECS.hpp>
    #include "ClientNamespace.hpp"

namespace RT::Client::Components {
    class OnlinePlayer : public GE::ECS::Components::AComponent {
        private:
        bool isConnected = false;
        int pid = -1;

        public:
        OnlinePlayer();
        void connected(bool isConnected);
        bool connected();
        void setPid(int pid);
        int getPid();
        void disconnect();
    };
}

#endif
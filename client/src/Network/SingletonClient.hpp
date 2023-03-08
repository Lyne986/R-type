#ifndef __RT_CLIENT_NETWORK_SINGLETON_CLIENT_HPP__
    #define __RT_CLIENT_NETWORK_SINGLETON_CLIENT_HPP__

    #include "Network/SingletonClient.hpp"
    #include <GameEngineNetwork.hpp>
    #include <memory>

namespace RT::Client::Network {
    class SingletonClient {
        public:
        static std::shared_ptr<GE::Network::Client::Client> getInstance();
    };
}

#endif
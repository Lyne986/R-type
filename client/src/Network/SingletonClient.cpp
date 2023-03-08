#include "Network/SingletonClient.hpp"

namespace RT::Client::Network {

    std::shared_ptr<GE::Network::Client::Client> SingletonClient::getInstance() {
        static std::shared_ptr<GE::Network::Client::Client> instance = std::make_shared<GE::Network::Client::Client>();
        return (instance);
    }

}
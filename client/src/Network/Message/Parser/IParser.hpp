#ifndef __RT_CLIENT_NETWORK_MESSAGE_PARSER_IPARSER_HPP__
    #define __RT_CLIENT_NETWORK_MESSAGE_PARSER_IPARSER_HPP__

    #include "NetworkNamespace.hpp"
    #include <GameEngineNetwork.hpp>
    #include <memory>

namespace RT::Client::Network::Message::Parser {
    class IParser {
        public:
            virtual void parse(std::shared_ptr<RT::GE::Network::Client::Client> client, message_s<CustomMsgTypes> msg) = 0;
    };
}

#endif
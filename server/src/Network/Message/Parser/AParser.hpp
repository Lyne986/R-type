#ifndef __RT_SERVER_NETWORK_MESSAGE_PARSER_APARSER_HPP__
    #define __RT_SERVER_NETWORK_MESSAGE_PARSER_APARSER_HPP__

    #include "NetworkNamespace.hpp"
    #include "Network/MyServer.hpp"

namespace RT::Server::Network::Message::Parser {
    class AParser {
        protected:
            MyServer &server;

        public:
            AParser(MyServer &server);
            virtual void parse(std::shared_ptr<Connection<CustomMsgTypes>> client, message_s<CustomMsgTypes>& msg) = 0;
    };
}

#endif
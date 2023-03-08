/*
** EPITECH PROJECT, 2022
** rtype
** File description:
** ListRoom
*/

#ifndef __RT_CLIENT_NETWORK_MESSAGE_PARSER_LISTROOM_HPP__
    #define __RT_CLIENT_NETWORK_MESSAGE_PARSER_LISTROOM_HPP__

    #include "AParser.hpp"
    #include "NetworkNamespace.hpp"
    #include "Scenes/RoomScene.hpp"
    #include <GameEngineECS.hpp>
    #include <GameEngineNetwork.hpp>
    #include <GameEngineScene.hpp>
    #include <memory>

namespace RT::Client::Network::Message::Parser {

    class ListRoom : public AParser {
        public:
            ListRoom(std::shared_ptr<GE::Scene::SceneManager> sceneManager);
            void parse(std::shared_ptr<RT::GE::Network::Client::Client> client, message_s<CustomMsgTypes> msg);
    };

}

#endif
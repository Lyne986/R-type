/*
** EPITECH PROJECT, 2022
** B-CPP-500-MPL-5-1-rtype-hugo.marrasse
** File description:
** main
*/

#define SDL_MAIN_HANDLED
#include "main.hpp"

int main(void)
{
    try {
        int count = 0;


        RT::Server::Network::MyServer server(60000);
        RT::Server::Network::Message::Parser::Parser parser(server);
        RT::Server::GameLogic::Game game;
        server.start();

        server.setOnMessage([&](std::shared_ptr<Connection<CustomMsgTypes>> client, message_s<CustomMsgTypes>& msg) {
            parser.parseMessage(client, msg);
        });
        server.setOnMessageUdp([&](std::shared_ptr<Connection<CustomMsgTypes>> client, message_s<CustomMsgTypes>& msg) {
            // std::cout << "TKT UDP " << count << std::endl;
            count++;
            parser.parseMessage(client, msg);
        });
        std::thread _TcpThread = std::thread([&]()
        {
            // std::cout << "TCP Thread" << std::endl;
            while (1) {
                server.update(-1, true);
            }
        });
        std::thread _UdpThread = std::thread([&]()
        {
            // std::cout << "UDP Thread" << std::endl;
            while (1) {
                server.updateUdp(-1, true);
            }
        });
        while (1) {
            game.update();
        }
        while (1) {
            if (_TcpThread.joinable())
                _TcpThread.join();
            if (_UdpThread.joinable())
                _UdpThread.join();
        }

        // while (1) {
        //     server.update(-1, true);
        //     server.updateUdp(-1, true);
        // }

        return (0);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
        return (84);
    }
}

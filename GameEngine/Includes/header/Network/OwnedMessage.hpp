/*
** EPITECH PROJECT, 2022
** B-CPP-500-MPL-5-1-rtype-hugo.marrasse
** File description:
** OwnedMessage
*/

#ifndef OWNEDMESSAGE_HPP_
    #define OWNEDMESSAGE_HPP_

    #include "Network/Message.hpp"

template <typename T>
class Connection;

template <typename T>
struct owned_message_s {
    std::shared_ptr<Connection<T>> remote = nullptr;
    message_s<T> msg;
};

template <typename T>
std::ostream& operator<<(std::ostream &os, const owned_message_s<T> &msg)
{
    os << msg.msg;
    return os;
}

#endif /* !OWNEDMESSAGE_HPP_ */

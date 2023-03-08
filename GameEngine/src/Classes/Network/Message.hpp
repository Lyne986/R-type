/*
** EPITECH PROJECT, 2022
** rtype
** File description:
** Message
*/

#ifndef MESSAGE_HPP_
    #define MESSAGE_HPP_

    #pragma once
    #include "Network/Utils.hpp"
    #include "Network/Connection.hpp"
    #include "Network/Header.hpp"
    #include <cstring>
    #include <memory>

template <typename T>
class Connection;

template <typename T>
struct message_s {
    header_s<T> header{};
    std::vector<uint8_t> body;

    message_s(std::string type = "")
    {
        memset(this->header.type, 0, MAX_TYPE_SIZE);
        strcpy(this->header.type, type.c_str());
    }

    ~message_s()
    {
        this->body.clear();
        
    }

    size_t size() const
    {
        return body.size();
    }
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const message_s<T>& msg)
{
    os << "ID:" << int(msg.header.id) << " Size:" << msg.header.size;
    os << " Body:[" << msg.body.data() << "]";
    return os;
}

template<typename T, typename DataType>
message_s<T>& operator<<(message_s<T>& msg, const DataType& data)
{
    static_assert(std::is_standard_layout<DataType>::value, "Too complex for a vector");
    size_t i = msg.body.size();

    msg.body.resize(msg.body.size() + sizeof(DataType));
    std::memcpy(msg.body.data() + i, &data, sizeof(DataType));
    msg.header.size = msg.size();

    return msg;
}

template<typename T, typename DataType>
message_s<T>& operator>>(message_s<T>& msg, DataType& data)
{
    static_assert(std::is_standard_layout<DataType>::value, "too complex for a vector");
    size_t i = msg.body.size() - sizeof(DataType);

    std::memcpy(&data, msg.body.data() + i, sizeof(DataType));
    msg.body.resize(i);
    msg.header.size = msg.size();

    return msg;
}

#endif /* !MESSAGE_HPP_ */

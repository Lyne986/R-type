/*
** EPITECH PROJECT, 2022
** rtype
** File description:
** SingletonIdRoom
*/

#include "SingletonIdRoom.hpp"

namespace RT::Client {

    int SingletonIdRoom::getId()
    {
        return _id;
    }
    void SingletonIdRoom::setId(int id)
    {
        _id = id;
    }
};

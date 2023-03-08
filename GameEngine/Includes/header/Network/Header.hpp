/*
** EPITECH PROJECT, 2022
** rtype
** File description:
** Header
*/

#ifndef HEADER_HPP_
    #define HEADER_HPP_

    #define MAX_TYPE_SIZE 100

template <typename T>
struct header_s {
    T id{};
    uint32_t size = 0;
    char type[MAX_TYPE_SIZE];
};

#endif /* !HEADER_HPP_ */

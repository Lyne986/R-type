/*
** EPITECH PROJECT, 2022
** rtype
** File description:
** SingletonIdRoom
*/

#ifndef __RT_CLIENT_NETWORK_SINGLETONID_ROOM_HPP__
    #define __RT_CLIENT_NETWORK_SINGLETONID_ROOM_HPP__

    #include <memory>

namespace RT::Client {
    class SingletonIdRoom {
        public:
            SingletonIdRoom() {};
            ~SingletonIdRoom() {};
            int getId();
            void setId(int id);
            static std::shared_ptr<SingletonIdRoom> getInstance()
            {
                static std::shared_ptr<SingletonIdRoom> instance = std::make_shared<SingletonIdRoom>();
                return instance;
            }
        
        private:
            int _id;
    };
}
#endif
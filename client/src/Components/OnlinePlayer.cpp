#include "Components/OnlinePlayer.hpp"

namespace RT::Client::Components {
    OnlinePlayer::OnlinePlayer()
    : AComponent("OnlinePlayer")
    {
    }

    void OnlinePlayer::connected(bool isConnected) {
        this->isConnected = isConnected;
    }

    bool OnlinePlayer::connected() {
        return (this->isConnected);
    }

    void OnlinePlayer::setPid(int pid) {
        this->pid = pid;
    }

    int OnlinePlayer::getPid() {
        return (this->pid);
    }

    void OnlinePlayer::disconnect() {
        this->isConnected = false;
        this->pid = -1;
    }
}

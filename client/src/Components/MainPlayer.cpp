#include "Components/MainPlayer.hpp"

namespace RT::Client::Components {

    bool MainPlayer::isConnected() const {
        return (this->connected);
    }

    void MainPlayer::isConnected(bool connected) {
        this->connected = connected;
    }

    void MainPlayer::setPid(int pid) {
        this->pid = pid;
    }

    int MainPlayer::getPid() const {
        return this->pid;
    }

}
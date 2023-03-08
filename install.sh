#!/bin/bash

version=$1

NO_FORMAT="\033[0m"
F_UNDERLINED="\033[4m"
F_BOLD="\033[1m"

C_WHITE="\033[38;5;15m"

help() {
    echo -e "${F_UNDERLINED}${F_BOLD}${C_WHITE}CUSAGE: ./install.sh Commands${NO_FORMAT}"
    echo -e "\n${C_WHITE}Installer for R-Type on linux${NO_FORMAT}"
    echo -e "\n${F_BOLD}${C_WHITE}Commands:${NO_FORMAT}"
    echo -e "\n\t${C_WHITE}build${NO_FORMAT}\tTry to Build part of project (client, server, GameEngine) if no argument is given all of them will be compiled (The client will compile the GameEngine)"
    echo -e "\t${C_WHITE}clean${NO_FORMAT}\t\tClean the project"
}

buildall() {
    unzip assets.zip
    cd build
    cmake ../ -DSDL2MIXER_VENDORED=OFF -DSDL2MIXER_OPUS=OFF -DSDL2MIXER_FLAC=OFF -DSDL2MIXER_MOD=OFF -DSDL2MIXER_MIDI=OFF
    make
    cd ../
    cp build/client/r-type_client .
    cp build/server/r-type_server .
}

buildall_i() {
    cd GameEngine
    python3 ./scripts/genIncludes.py
    cd ../
    cd build
    cmake ../ -DSDL2MIXER_VENDORED=OFF -DSDL2MIXER_OPUS=OFF -DSDL2MIXER_FLAC=OFF -DSDL2MIXER_MOD=OFF -DSDL2MIXER_MIDI=OFF
    make
    cd ../
    cp build/client/r-type_client .
    cp build/server/r-type_server .
}

if [ $1 == "build" ]; then
    buildall
    exit 0
elif [ $1 == "build_i" ]; then
    buildall_i
    exit 0
else
    help
fi

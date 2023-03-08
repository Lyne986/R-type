/*
** EPITECH PROJECT, 2022
** B-CPP-500-MPL-5-1-rtype-hugo.marrasse
** File description:
** ClientNamespace.hpp
*/

#ifndef __RT_CLIENTNAMESPACE_HPP__
#define __RT_CLIENTNAMESPACE_HPP__

namespace RT::Client
{
    class Core;

    namespace Components
    {
        class OnlinePlayer;
        class MainPlayer;
        class Health;
        class Damage;
        class Enemy;
        class ButtonScene;
        class ButtonSound;
        class ChangeKey;
        class Score;
        class HealthUI;
        class CreateRoom;
        class JoinRoom;
        class SelectRoom;
        class UnselectRoom;
    }

    namespace Systems
    {
        class OnlinePlayer;
        class MainPlayer;
        class InputSystem;
        class HealthSystem;
        class EnemySystem;
        class ClickButtonSceneSystem;
        class HoverButtonSceneSystem;
        class ReleaseButtonSceneSystem;
        class ChangeKeySystem;
        class ScoreSystem;
        class ChangeSoundSystem;
        class HoverCreateRoomSystem;
        class HoverSelectRoomSystem;
        class HoverUnselectRoomSystem;
        class HoverJoinRoomSystem;
    }

    namespace Scenes
    {
        class GameScene;
        class MenuScene;
        class OptionScene;
        class RoomScene;
    }

    namespace Transitions
    {
        class ATransition;
        class GameStart;
        class GameOver;
        class GameWon;
    }
};

#endif

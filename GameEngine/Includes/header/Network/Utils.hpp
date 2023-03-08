/*
** EPITECH PROJECT, 2022
** B-CPP-500-MPL-5-1-rtype-hugo.marrasse
** File description:
** Utils
*/

#ifndef UTILS_HPP_
	#define UTILS_HPP_

	#include <memory>
	#include <mutex>
	#include <deque>
	#include <optional>
	#include <thread>
	#include <vector>
	#include <iostream>
	#include <algorithm>
	#include <cstdint>
	#include <chrono>
	#include <asio.hpp>
	#include <asio/ts/buffer.hpp>
	#include <asio/ts/internet.hpp>

enum class CustomMsgTypes : uint32_t
{
	ServerAccept,
	ServerDeny,
	ServerPing,
	messageAll,
	ServerMessage,
	CreateRoom,
	RoomList,
	JoinRoom,
};

	#ifdef _WIN32
		#define _WIN32_WINNT 0x0A00
		#define ASIO_STANDALONE
	#endif

#endif /* !UTILS_HPP_ */

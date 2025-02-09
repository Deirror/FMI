#pragma once

#include <deque>
#include <mutex>	
#include <memory>
#include <thread>
#include <chrono>
#include <vector>
#include <cstdint>
#include <optional>
#include <iostream>
#include <algorithm>

#ifdef _WIN32
#define _WIN32_WINNT 0x0A00
#endif


#define ASIO_STANDALONE
#include <asio.hpp>
#include <asio/ts/buffer.hpp>
#include <asio/ts/internet.hpp>

#define NET_BEGIN namespace net {
#define NET_END }
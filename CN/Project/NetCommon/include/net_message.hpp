#pragma once
#include "net_include.h"

NET_BEGIN

template <typename T>
struct message_header 
{
	T id{};
	uint64_t size = 0;
};

template <typename T>
struct message
{
	message_header<T> header{};
	std::vector<uint8_t> body;

	inline uint64_t size() const
	{
		return sizeof(message_header<T>) + body.size();
	}

	inline friend std::ostream& operator<<(std::ostream& os, const message<T>& msg)
	{
		return (os << "ID:" << msg.header.id << " Size: " << msg.header.size);
	}

	template <typename DataType>
	friend message<T>& operator<<(message<T>& msg, const DataType& data)
	{
		//static_assert(std::is_standart_layout<DataType>::value, "Data is too complex to be pushed into vector");

		uint64_t old_size = msg.body.size();

		msg.body.resize(msg.body.size() + sizeof(DataType));

		std::memcpy(msg.body.data() + old_size, &data, sizeof(DataType));

		msg.header.size = msg.size();

		return msg;
	}

	template <typename DataType>
	friend message<T>& operator>>(message<T>& msg, DataType& data)
	{
		//static_assert(std::is_standart_layout_v<DataType>(), "Data is too complex to be pushed into vector");

		uint64_t updated_size = msg.body.size() - sizeof(DataType);

		std::memcpy(&data, msg.body.data() + updated_size, sizeof(DataType));

		msg.body.resize(updated_size);

		msg.header.size = msg.size();

		return msg;
	}
};

template<typename T>
class connection;

template<typename T>
struct owned_message
{
	std::shared_ptr<connection<T>> remote = nullptr;
	message<T> msg;

	inline friend std::ostream& operator<<(std::ostream& os, const owned_message<T>& msg)
	{
		return (os << msg.msg);
	}
};

NET_END
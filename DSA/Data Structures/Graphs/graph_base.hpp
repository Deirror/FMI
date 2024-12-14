#pragma once
#include <utility>

using namespace std;

template <typename T>
class graph_base {
public:
	virtual void add(const pair<T, T>& edge) = 0;
	virtual void add(const T& vertex) = 0;

	virtual void remove(const pair<T, T>& vertex) = 0;
	virtual void remove(const T& vertex) = 0;

	virtual bool contains(const pair<T, T>& edge) const = 0;
	virtual bool contains(const T& vertex) const = 0;

	virtual bool is_connected() const = 0;

	virtual bool has_cycle() const = 0;

	virtual size_t path(const T& startVertex, const T& endVertex) const = 0;
};

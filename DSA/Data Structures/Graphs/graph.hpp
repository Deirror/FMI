#pragma once
#include <unordered_set>
#include <unordered_map>

#include <iostream>

#include <vector>
#include <queue>

#include "graph_base.hpp"

template <typename T>
class graph : public graph_base<T> {
public:
	graph() = default;

	graph(const vector<pair<T, T>>& edges) {
		for (const auto& edge : edges) {
			add(edge);
		}
	}

	graph(const vector<vector<T>>& adjacencyMatrix, const vector<T>& values) {
		size_t n = adjacencyMatrix.size();
		for (size_t i = 0; i < n; i++) {
			for (size_t j = i; j < n; j++) {
				if (adjacencyMatrix[i][j]) {
					add({values[i], values[j]});
				}
			}
		}
	}

	graph(const vector<T>& values, const vector<unordered_set<T>>& adjacencyList) {
		size_t n = adjacencyList.size();
		for (size_t i = 0; i < n; i++) {
			edgeList[values[i]] = adjacencyList[i];
		}
	}

	void add(const pair<T, T>& edge) override {
		edgeList[edge.first].insert(edge.second);
		edgeList[edge.second].insert(edge.first);
	}

	void add(const T& vertex) override {
		edgeList[vertex];
	}

	void remove(const pair<T, T>& edge) override {
		if (!doesEdgeExist(edge)) {
			return;
		}
		edgeList[edge.second].erase(edge.first);
		edgeList[edge.first].erase(edge.second);
	}

	void remove(const T& vertex) override {
		if (!doesVertexExist(vertex)) {
			return;
		}
		auto& connectedVertexes = edgeList[vertex];
		for (auto& connectedVertex : connectedVertexes) {
			edgeList[connectedVertex].erase(vertex);
		}
		edgeList.erase(vertex);
	}

	bool contains(const pair<T, T>& edge) const override {
		return doesEdgeExist(edge);
	}

	bool contains(const T& vertex) const override {
		return doesVertexExist(vertex);
	}

	bool is_connected() const override {
		if (edgeList.empty()) {
			return false;
		}
		auto vertex = *(edgeList.begin());
		unordered_set<T> visited;
		queue<const unordered_set<T>*> q;
		visited.insert(vertex.first);
		q.push(&vertex.second);
		while (q.size()) {
			auto& connectedVertexes = *(q.front());
			for (auto& connectedVertex : connectedVertexes) {
				if (visited.find(connectedVertex) == visited.end()) {
					visited.insert(connectedVertex);
					q.push(&edgeList.at(connectedVertex));
				}
			}
			q.pop();
		}
		return visited.size() == edgeList.size();
	}

	bool has_cycle() const override {
		unordered_set<T> values;
		for (auto& vertexInfo : edgeList) {
			values.insert(vertexInfo.first);
		}
		if (is_connected()) {
			return has_cycle_connected_component(values);
		}
		else {
			while (values.size()) {
				if (has_cycle_connected_component(values)) {
					return true;
				}
			}
			return false;
		}
	}

	size_t path(const T& startVertex, const T& endVertex) const override {
		if (!doesVertexExist(startVertex) || !doesVertexExist(endVertex)) {
			return 0;
		}
		unordered_map<T, size_t> visited;
		queue<unordered_map<T, unordered_set<T>>::const_iterator> q;
		visited[startVertex] = 0;
		q.push(edgeList.find(startVertex));
		while (q.size()) {
			auto& connectedVertexes = *(q.front());
			for (auto& connectedVertex : connectedVertexes.second) {
				if (connectedVertex == endVertex) {
					return visited[connectedVertexes.first] + 1;
				}
				if (visited.find(connectedVertex) == visited.end()) {
					visited[connectedVertex] = visited[connectedVertexes.first] + 1;
					q.push(edgeList.find(connectedVertex));
				}
			}
			q.pop();
		}
		return 0;
	}

private:
	bool has_cycle_connected_component(unordered_set<T>& values) const {
		auto vertex = *(values.begin());
		unordered_set<T> visited;
		queue<unordered_map<T, unordered_set<T>>::const_iterator> q;
		visited.insert(vertex);
		q.push(edgeList.find(vertex));
		while (q.size()) {
			auto& connectedVertexes = *(q.front());
			for (auto& connectedVertex : connectedVertexes.second) {
				if (visited.find(connectedVertex) != visited.end() &&
					values.find(connectedVertex) != values.end()) {
					return true;
				}
				if (visited.find(connectedVertex) == visited.end()) {
					visited.insert(connectedVertex);
					q.push(edgeList.find(connectedVertex));
				}
			}
			values.erase(connectedVertexes.first);
			q.pop();
		}
		return false;
	}

	bool doesEdgeExist(const pair<T, T>& edge) const {
		if (!doesVertexExist(edge.first) || !doesVertexExist(edge.second)) {
			return false;
		}
		const auto& firstSet = edgeList.at(edge.first);
		const auto& secondSet = edgeList.at(edge.second);
		return firstSet.find(edge.second) != firstSet.end() &&
			   secondSet.find(edge.first) != secondSet.end();
	}

	bool doesVertexExist(const T& vertex) const {
		return edgeList.find(vertex) != edgeList.end();
	}

	unordered_map<T, unordered_set<T>> edgeList;
};

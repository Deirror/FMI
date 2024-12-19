void dfs(WeightedDirectedGraph graph, int v, bool* visited, stack<int> topoOrder) {
  visited[v] = true;
  for (WeightedEdge e : graph.adj(v)) {
      if (!visited[e.to()]) {
          dfs(graph, e.to(), visited, topoOrder);
      }
  }
  topoOrder.push(v);
}

stack<int> topoSort(WeightedDirectedGraph graph) {
  stack<int> topoOrder = stack<int>();
  bool* visited = new bool[graph.vertices()];
  for (int i = 0; i < graph.vertices(); i++) {
      if (!visited[i]) {
          dfs(graph, i, visited, topoOrder);
      }
  }
}

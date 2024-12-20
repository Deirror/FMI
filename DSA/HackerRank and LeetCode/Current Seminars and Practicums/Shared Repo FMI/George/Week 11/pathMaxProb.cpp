class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        unordered_map<int, vector<pair<int, double>>> graph;
        for(size_t i = 0; i < edges.size(); i++) {
            graph[edges[i][0]].push_back({ edges[i][1], succProb[i] });
            graph[edges[i][1]].push_back({ edges[i][0], succProb[i] });
        }
        
        vector<double> probs(n, 0);
        probs[start_node] = 1;
        priority_queue<pair<double, int>> nextToProcess;
        nextToProcess.push({1., start_node});
        
        while(!nextToProcess.empty()) {
            auto toProcess = nextToProcess.top();
            nextToProcess.pop();
            if(toProcess.first > probs[toProcess.second]) continue;
            if(toProcess.second == end_node) {
                return probs[end_node];
            }

            for(auto& adj: graph[toProcess.second]) {
                double possibleProb = probs[toProcess.second] * adj.second;
                if(probs[adj.first] < possibleProb) {
                    probs[adj.first] = possibleProb;
                    nextToProcess.push({ possibleProb, adj.first });
                }
            }
        }
        
        return probs[end_node];
    }
};

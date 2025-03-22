class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<bool> visited(n, false);

        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        int completeComponents = 0;

        function<pair<int, int>(int)> dfs = [&](int node) {
            visited[node] = true;
            int nodes = 1, edges = adj[node].size();
            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    auto [subNodes, subEdges] = dfs(neighbor);
                    nodes += subNodes;
                    edges += subEdges;
                }
            }
            return make_pair(nodes, edges);
        };

        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                auto [nodes, edges] = dfs(i);
                if (edges / 2 == nodes * (nodes - 1) / 2) {
                    completeComponents++;
                }
            }
        }
        
        return completeComponents;
    }
};

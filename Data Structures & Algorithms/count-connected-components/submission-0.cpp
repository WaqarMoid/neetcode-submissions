class Solution {
    private:
    void dfs(int node, const vector<vector<int>>& adj, vector<bool>& visited) {
        visited[node] = true;
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, adj, visited);
            }
        }
    }

public:
    int countComponents(int n, vector<vector<int>>& edges) {
        // Step 1: Build Undirected Adjacency List
        vector<vector<int>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        // Step 2 & 3: Iterate and Count Components
        vector<bool> visited(n, false);
        int componentCount = 0;

        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                componentCount++;
                dfs(i, adj, visited);
            }
        }

        return componentCount;
    }
};

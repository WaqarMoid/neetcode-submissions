class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1) return false;

        // Step 2: Build Undirected Adjacency List
        vector<vector<int>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        // Step 3: BFS to check connectivity
        queue<int> q;
        vector<bool> visited(n, false);

        q.push(0);
        visited[0] = true;
        int visitedCount = 0;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            visitedCount++;

            for (int neighbor : adj[curr]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }

        // Step 4: If all nodes were visited, it's a fully connected valid tree
        return visitedCount == n;
    }
};

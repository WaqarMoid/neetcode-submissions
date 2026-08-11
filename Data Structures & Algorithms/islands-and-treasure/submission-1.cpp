class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
     int m = grid.size();
        int n = grid[0].size();
        
        queue<pair<int, int>> q;

        // Step 1: Push all treasure chests (0) into queue as BFS starting points
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }

        // Direction pair vector (Your preferred style)
        static const vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        // Step 2: Multi-Source BFS outwards from all treasures simultaneously
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (auto& dir : directions) {
                int nr = r + dir.first;
                int nc = c + dir.second;

                // Check bounds and if cell is an unvisited land cell (INF)
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 2147483647) {
                    grid[nr][nc] = grid[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }
    }
};

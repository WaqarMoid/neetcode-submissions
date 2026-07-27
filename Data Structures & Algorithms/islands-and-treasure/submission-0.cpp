class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
    if (grid.empty()) return;

        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int, int>> q;

        // Step 1: Add all treasure chests (0s) to the queue as starting sources
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (grid[r][c] == 0) {
                    q.push({r, c});
                }
            }
        }

        // Direction offsets for: Up, Down, Left, Right
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        // Step 2: Multi-Source BFS
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (const auto& dir : directions) {
                int nr = r + dir.first;
                int nc = c + dir.second;

                // Step 3: Check bounds and if neighbor is an unvisited land cell (INF)
                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] == 2147483647) {
                    grid[nr][nc] = grid[r][c] + 1; // Distance to nearest treasure
                    q.push({nr, nc});               // Push updated cell to continue BFS
                }
            }
        }    
    }
};

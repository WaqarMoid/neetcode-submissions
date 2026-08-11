class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int minutes = 0;    
        int freshCount = 0;
        queue<pair<int, int>> q;

        // Step 1: Push all rotten oranges (2) into queue and count fresh oranges (1)
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    freshCount++;
                }
            }
        }

        // Edge case: If there are no fresh oranges, 0 minutes are needed
        if (freshCount == 0) return 0;

        // Direction pair vector (Your preferred style)
        static const vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        // Step 2: Level-by-Level Multi-Source BFS
        while (!q.empty() && freshCount > 0) {
            int size = q.size(); // Number of rotten oranges in current minute

            for (int k = 0; k < size; k++) {
                auto [r, c] = q.front();
                q.pop();

                for (auto& dir : directions) {
                    int nr = r + dir.first;
                    int nc = c + dir.second;

                    // Standard BFS boundary check & fresh orange check
                    if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 1) {
                        grid[nr][nc] = 2; // Rot the orange
                        q.push({nr, nc});
                        freshCount--;     // Decrement remaining fresh count
                    }
                }
            }
            minutes++; // Increment time once per level/minute
        }

        // If fresh oranges remain that couldn't be reached, return -1
        return freshCount == 0 ? minutes : -1;   
    }
};
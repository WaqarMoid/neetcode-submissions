class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));

        // 1. Run DFS for Top (Pacific) and Bottom (Atlantic) borders
        for (int j = 0; j < n; j++) {
            dfs(heights, 0, j, pacific, heights[0][j]);             // Top row (Pacific)
            dfs(heights, m - 1, j, atlantic, heights[m - 1][j]);     // Bottom row (Atlantic)
        }

        // 2. Run DFS for Left (Pacific) and Right (Atlantic) borders
        for (int i = 0; i < m; i++) {
            dfs(heights, i, 0, pacific, heights[i][0]);             // Left col (Pacific)
            dfs(heights, i, n - 1, atlantic, heights[i][n - 1]);     // Right col (Atlantic)
        }

        // 3. Cells reachable by both oceans form the result
        vector<vector<int>> result;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    result.push_back({i, j});
                }
            }
        }

        return result;
    }

private:
    void dfs(vector<vector<int>>& heights, int r, int c, vector<vector<bool>>& visited, int prevHeight) {
        // Standard DFS guard clause: boundary check, visited check, or height constraint (flowing uphill)
        if (r < 0 || r >= heights.size() || c < 0 || c >= heights[0].size() || visited[r][c] || heights[r][c] < prevHeight) {
            return;
        }

        visited[r][c] = true;

        // Direction pair vector (Your preferred style)
        static const vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        for (auto& dir : directions) {
            dfs(heights, r + dir.first, c + dir.second, visited, heights[r][c]);
        }
    }
};

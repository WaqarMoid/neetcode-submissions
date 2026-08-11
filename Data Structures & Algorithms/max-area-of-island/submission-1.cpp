class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxarea = 0;
        int m = grid.size();
        int n = grid[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    maxarea = max(maxarea, dfs(grid, i, j));
                }
            }
        }
        return maxarea;
    }

private:
    int dfs(vector<vector<int>>& grid, int i, int j) {
        // Boundary and water checks
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0) {
            return 0;
        }

        // Sink the land
        grid[i][j] = 0;

        int area = 1;

        // Best Practice 1: 'static const' avoids heap allocations on recursion
        static const vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        for (auto& dir : directions) {
            area += dfs(grid, i + dir.first, j + dir.second);
        }

        return area;
    }
};

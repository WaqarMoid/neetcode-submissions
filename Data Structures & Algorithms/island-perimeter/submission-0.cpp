class Solution {
private:
    int perimeter = 0;
    int m = 0;
    int n = 0;

    int dfs(vector<vector<int>>& grid, int i, int j, int m, int n) {
        int result = 0;
        vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        
        if (i < 0 || i >= m || j >= n || j < 0 || grid[i][j] == 0) {
            return 1;
        }
        if (grid[i][j] == -1) {
            return 0;
        }
        
        grid[i][j] = -1;
        
        for (const auto& dir : directions) {
            result += dfs(grid, i + dir[0], j + dir[1], m, n);
        }
        
        return result;
    }

public:
    int islandPerimeter(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        perimeter = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    return dfs(grid, i, j, m, n);
                }
            }
        }
        
        return perimeter;
    }
};
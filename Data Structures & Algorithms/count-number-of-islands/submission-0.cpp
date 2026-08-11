class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
    int c = 0;
        int m = grid.size();
        int n = grid[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    c += 1;
                    dfs(grid, i, j);
                }
            }
        }
        return c;
    }

private:
    void dfs(vector<vector<char>>& grid, int i, int j) {
        // Boundary and water checks
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == '0') {
            return;
        }

        // Sink the land
        grid[i][j] = '0';

        vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        for (auto& dir : directions) {
            dfs(grid, i + dir[0], j + dir[1]);
        }
    }
};

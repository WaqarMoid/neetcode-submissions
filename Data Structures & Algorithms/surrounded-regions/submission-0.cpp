class Solution {
private:
    int rows, cols;
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    void dfs(vector<vector<char>>& board,int r, int c)
    {
        if(r < 0 || c < 0 || r >= rows || c >= cols || board[r][c] != 'O')
        {
            return;
        }

        board[r][c]='T';

        for(const auto& dir:directions)
        {
            dfs(board, r+dir.first,c+dir.second);
        }
    }
public:
    void solve(vector<vector<char>>& board) 
    {
       if (board.empty()) return;

        rows = board.size();
        cols = board[0].size();

        // Step 1: Run DFS for all 'O's on the Top and Bottom borders
        for (int c = 0; c < cols; ++c) {
            if (board[0][c] == 'O') dfs(board, 0, c);
            if (board[rows - 1][c] == 'O') dfs(board, rows - 1, c);
        }

        // Step 1: Run DFS for all 'O's on the Left and Right borders
        for (int r = 0; r < rows; ++r) {
            if (board[r][0] == 'O') dfs(board, r, 0);
            if (board[r][cols - 1] == 'O') dfs(board, r, cols - 1);
        }

        // Step 2 & 3: Post-process the board
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (board[r][c] == 'O') {
                    board[r][c] = 'X'; // Surrounded 'O' -> Capture
                } else if (board[r][c] == 'T') {
                    board[r][c] = 'O'; // Safe 'T' -> Restore to 'O'
                }
            }
        }
    }
};

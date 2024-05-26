class Solution {
private:
    int m, n;
    vector<pair<int, int>> movements = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>>& board) {
        vis[row][col] = 1;

        for (auto& move : movements) {
            int new_row = row + move.first;
            int new_col = col + move.second;
            if (new_row >= 0 && new_col >= 0 && new_row < m && new_col < n && board[new_row][new_col] == 'O' && !vis[new_row][new_col]) {
                dfs(new_row, new_col, vis, board);
            }
        }
    }

public:
    void solve(vector<vector<char>>& board) {
        m = board.size();
        if (m == 0) return;
        n = board[0].size();
        
        vector<vector<int>> vis(m, vector<int>(n, 0));

        // Traverse the boundary cells
        for (int i = 0; i < m; ++i) {
            if (board[i][0] == 'O' && !vis[i][0]) dfs(i, 0, vis, board);
            if (board[i][n-1] == 'O' && !vis[i][n-1]) dfs(i, n-1, vis, board);
        }
        for (int j = 0; j < n; ++j) {
            if (board[0][j] == 'O' && !vis[0][j]) dfs(0, j, vis, board);
            if (board[m-1][j] == 'O' && !vis[m-1][j]) dfs(m-1, j, vis, board);
        }

        // Replace unvisited 'O' with 'X'
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!vis[i][j] && board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
class Solution {
private:
    int m,n;
    vector<pair<int, int>> movements = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<int>>& grid) {
        vis[row][col] = 1;

        for (auto& move : movements) {
            int new_row = row + move.first;
            int new_col = col + move.second;
            if (new_row >= 0 && new_col >= 0 && new_row < m && new_col < n && grid[new_row][new_col] == 1 && !vis[new_row][new_col]) {
                dfs(new_row, new_col, vis, grid);
            }
        }
    }

public:
    int numEnclaves(vector<vector<int>>& grid) {
        m = grid.size();
        // if (m == 0) return;
        n = grid[0].size();
        
        vector<vector<int>> vis(m, vector<int>(n, 0));

        // Traverse the boundary cells
        for (int i = 0; i < m; ++i) {
            if (grid[i][0] == 1 && !vis[i][0]) dfs(i, 0, vis, grid);
            if (grid[i][n-1] == 1 && !vis[i][n-1]) dfs(i, n-1, vis, grid);
        }
        for (int j = 0; j < n; ++j) {
            if (grid[0][j] == 1 && !vis[0][j]) dfs(0, j, vis, grid);
            if (grid[m-1][j] == 1 && !vis[m-1][j]) dfs(m-1, j, vis, grid);
        }

        int enclaveCount = 0;

        // Count the number of enclaves
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1 && !vis[i][j]) {
                    enclaveCount++;
                }
            }
        }

        return enclaveCount;
        
    }
};
class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        if (i == 0 && j == 0) return grid[i][j]; // Base case: Start point
        if (i < 0 || j < 0) return 1e6; // Out of bounds

        if (dp[i][j] != -1) return dp[i][j]; // Return precomputed value

        // Recursively calculate the minimum path sum from left and up
        cout<<i<<" "<<j<<endl;
        int left = grid[i][j] + solve(i, j - 1, grid, dp);
        int up = grid[i][j] + solve(i - 1, j, grid, dp);

        dp[i][j] = min(left, up); // Store and return the result
        return dp[i][j];
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1)); // Initialize DP table

        // Solve the problem for the bottom-right corner
        return solve(m - 1, n - 1, grid, dp);
    }
};

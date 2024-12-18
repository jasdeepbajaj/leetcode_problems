class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp){
        int m = grid.size();
        int n = grid[0].size();
        if(i == 0 && j == 0) return grid[i][j];
        if(i < 0 || j < 0) return 1e6;
        if(dp[i][j] != -1) return dp[i][j];

        int left = grid[i][j] + solve(i, j-1, grid, dp);
        int up = grid[i][j] + solve(i-1, j, grid, dp);
        dp[i][j] = min(left, up);
        return dp[i][j]; 
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // if (m==1 && n==1) return grid[m-1][n-1];
        vector<vector<int>> dp(m, vector<int>(n,-1));
        return solve(m-1,n-1,grid, dp);
    }
};
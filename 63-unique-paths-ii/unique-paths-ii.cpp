class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp){
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if(i == m-1 && j == n-1) return 1;
        if(i >= m || j >=n || obstacleGrid[i][j] == 1) return 0;
        if(dp[i][j] != 0) return dp[i][j];

        int right = solve(i, j + 1, obstacleGrid, dp);
        int down = solve(i+1, j, obstacleGrid, dp);
        dp[i][j] = right + down;
        return dp[i][j]; 
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();   
        
        if (obstacleGrid[m-1][n-1] == 1)return 0;
        if (m==1 && n==1) return 1;
        vector<vector<int>> dp(m, vector<int>(n,0));
        solve(0,0,obstacleGrid, dp);
        return dp[0][0];
    }
};
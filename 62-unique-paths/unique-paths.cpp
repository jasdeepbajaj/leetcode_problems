class Solution {
public:
    int solve(int i, int j, int m, int n, vector<vector<int>> &dp) {
        if (i == m - 1 && j == n - 1) {
            return 1;
        }

        if (i >= m || j >= n) {
            return 0;
        }

        if (dp[i][j] != 0) {
            return dp[i][j];
        }

        int right = solve(i, j + 1, m, n, dp);  // Move right.
        int down = solve(i + 1, j, m, n, dp);   // Move down.

        dp[i][j] = right + down;
        return dp[i][j];
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));  // dp array to memoize results.
        return solve(0, 0, m, n, dp);  // Start the recursion from (0, 0).
    }
};

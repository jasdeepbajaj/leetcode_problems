class Solution {
public:

    int solve(int start, int n, vector<int> &dp){
        if (start == n) return 1;
        if (start > n) return 0;
        if (dp[start] != -1) return dp[start];
        int oneStep = solve(start+1, n, dp);
        int twoStep = solve(start+2, n, dp);

        dp[start] = oneStep + twoStep;

        return dp[start]; 

    }
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        return solve(0, n, dp);
    }
};
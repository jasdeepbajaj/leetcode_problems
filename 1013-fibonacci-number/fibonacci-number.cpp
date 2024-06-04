class Solution {
public:
    int fib(int n) {
        // Handle base cases
        if (n == 0) return 0;
        if (n == 1) return 1;
        
        // Create a dp array to store Fibonacci numbers up to n
        vector<int> dp(n + 1, -1);
        
        // Initialize the base cases
        dp[0] = 0;
        dp[1] = 1;

        // Fill the dp array iteratively
        for (int i = 2; i <= n; ++i) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        // Return the nth Fibonacci number
        return dp[n];
    }
};

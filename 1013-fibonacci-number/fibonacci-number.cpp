class Solution {
public:
    vector<int> dp;
    
    Solution() {
        // Initialize dp array with a size of 31 (0 to 30) and fill it with -1
        // Adjust the size if you need a larger range of Fibonacci numbers
        dp.resize(31, -1);
    }

    int fib(int n) {
        // Base cases: if n is 0 or 1, return n
        if (n <= 1) return n;
        
        // If the value has already been computed, return it
        if (dp[n] != -1) return dp[n];
        
        // Compute the Fibonacci number recursively and store the result in dp array
        dp[n] = fib(n - 1) + fib(n - 2);
        
        // Return the computed Fibonacci number
        return dp[n];
    }
};

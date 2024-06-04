class Solution {
public:
    int fib(int n) {
        // Handle base cases
        if (n == 0) return 0;
        if (n == 1) return 1;
        
        
        // Initialize the base cases
        int prev2 = 0;
        int prev = 1;

        // Fill the dp array iteratively
        for (int i = 2; i <= n; ++i) {
            int curri = prev + prev2;
            prev2 = prev;
            prev = curri;
        }

        // Return the nth Fibonacci number
        return prev;
    }
};

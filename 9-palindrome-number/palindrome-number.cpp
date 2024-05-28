class Solution {
public:
    bool isPalindrome(int x) {
        long ans = 0;
        int original = x;
        int rem;
        if (x<0) return false;
        while (x != 0) {
            rem = x % 10;
            ans = ans * 10 + rem;
            x /= 10;
        }
        
        if (ans > INT_MAX || ans < INT_MIN) {
            return false;
        }

        if (original == ans) return true;
        else return false;
    }
};
class Solution {

private:
    bool check_palindrome(string s, int n) {
        for (int i = 0; i < n / 2; i++) {
            if (s[i] != s[n - i - 1]) {
                return false;
            }
        }
        return true;
    }
    
    bool isSpecialCharacter(char ch) {
        if (ch >= 'A' && ch <= 'Z') return false;
        if (ch >= 'a' && ch <= 'z') return false;
        if (ch >= '0' && ch <= '9') return false;
        return true;
    }
    
    char toLowercase(char ch) {
        if (ch >= 'A' && ch <= 'Z') {
            return ch + ('a' - 'A');
        }
        return ch;
    }

public:
    bool isPalindrome(string s) {
        int n = s.size();
        string s_;
        
        for (int i = 0; i < n; i++) {
            if (!isSpecialCharacter(s[i])) {
                s_ += toLowercase(s[i]);
            }
        }
        
        int new_n = s_.size();
        return check_palindrome(s_, new_n);
    }
};

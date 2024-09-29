class Solution {
public:
    bool isNumber(string s) {
        int i = 0;
        int n = s.length();
        
        // Step 1: Handle leading whitespace (if any)
        while (i < n && s[i] == ' ') i++;
        
        // Step 2: Handle sign
        if (i < n && (s[i] == '+' || s[i] == '-')) i++;
        
        // Step 3: Handle digits before decimal point
        bool hasDigits = false;
        while (i < n && isdigit(s[i])) {
            i++;
            hasDigits = true;
        }
        
        // Step 4: Handle decimal point and digits after it
        if (i < n && s[i] == '.') {
            i++;
            while (i < n && isdigit(s[i])) {
                i++;
                hasDigits = true;
            }
        }
        
        // If no digits found yet, it's not a valid number
        if (!hasDigits) return false;
        
        // Step 5: Handle exponent
        if (i < n && (s[i] == 'e' || s[i] == 'E')) {
            i++;
            if (i < n && (s[i] == '+' || s[i] == '-')) i++;
            
            bool hasExponentDigits = false;
            while (i < n && isdigit(s[i])) {
                i++;
                hasExponentDigits = true;
            }
            
            if (!hasExponentDigits) return false;
        }
        
        // Step 6: Handle trailing whitespace (if any)
        while (i < n && s[i] == ' ') i++;
        
        // If we've reached the end of the string, it's a valid number
        return i == n;
    }
};
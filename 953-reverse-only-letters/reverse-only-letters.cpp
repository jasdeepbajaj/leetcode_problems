class Solution {
public:
    bool isLetter(char c) {
        return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
    }
    
    std::string reverseOnlyLetters(std::string s) {
        int left = 0, right = s.size() - 1;
        while (left < right) {
            while (left < right && !isLetter(s[left])) left++;
            while (left < right && !isLetter(s[right])) right--;
            swap(s[left], s[right]);
            left++;
            right--;
        }
        return s;
    }
};
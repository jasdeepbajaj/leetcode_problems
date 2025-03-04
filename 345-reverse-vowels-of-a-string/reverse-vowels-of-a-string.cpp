class Solution {
public:
    bool isVowel(char ch){
        if(ch == 'a' || ch == 'i' || ch == 'o' || ch == 'e' || ch == 'u' ||
           ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') return true;
        return false;
    }
    string reverseVowels(string s) {
        int left = 0;
        int right = s.size() - 1;
        while (left < right){
            while (left < right && !isVowel(s[left])) left ++;
            while (left < right && !isVowel(s[right])) right --;
            swap(s[left], s[right]);
            left++; right--;
        }

        return s;
    }
};
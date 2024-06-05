class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       int maxLen = 0;

       for (int i =0; i<s.size(); i++){
            map<char, int> dict;
            for (int j =i; j<s.size(); j++){
                if(dict[s[j]] == 1) break;
                
                int len = j - i + 1;
                maxLen = max(len, maxLen);
                dict[s[j]] = 1;
            }
       } 
       return maxLen;
    }
};
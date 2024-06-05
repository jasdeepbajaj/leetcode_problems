class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // int maxLen = 0;
        int left = 0;
        int right = 0;
        vector<int> hash(256, -1);
        int maxLen = 0;

        while (right<s.size()){
            if (hash[s[right]]!=-1){
                if (hash[s[right]]>=left){
                    left =  hash[s[right]] + 1;
                }
            }
            

            hash[s[right]] = right;
            int len = right - left + 1;
            maxLen = max(maxLen, len); 
            right ++;

        }
       return maxLen;
    }
};
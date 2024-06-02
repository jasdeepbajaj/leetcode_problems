class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        bool i_exist;
        
        for (int i = 0; i <= n; i++) {
            i_exist = false;
            for (int j = 0; j < n; j++) {
                if (nums[j] == i) {
                    i_exist = true;
                    break; // No need to continue the inner loop if we found the number
                }
            }
            if (!i_exist) return i;
        }
        
        // This return statement is just a safety net and should never be reached
        return -1;
    }
};
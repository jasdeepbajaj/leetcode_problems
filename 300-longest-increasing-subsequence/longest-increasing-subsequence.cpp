class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);

        if (n==0) return 0;

        for(int i = 1; i < n; ++i){
            for (int j = 0; j < i ; ++j){
                if(nums[i] > nums[j]){
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
        }

        int ans = INT_MIN;

        for(int i = 0; i<n; i++){
            if (dp[i] > ans){
                ans = dp[i];
            }
        }

        return ans;
    }
};
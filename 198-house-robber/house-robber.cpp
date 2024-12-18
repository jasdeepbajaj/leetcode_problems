class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> loot(n, INT_MIN);
        if(n==1) return nums[n-1];
        loot[0] = nums[0];
        loot[1] = max(nums[0], nums[1]);
        for(int i = 2; i<n; ++i){
            loot[i] = max(loot[i-1], nums[i] + loot[i-2]);
            
        }

        return loot[n-1];   

    }
};
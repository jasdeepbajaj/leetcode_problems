class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);
        vector<int> skipFirstHouse(n-1, INT_MIN);
        skipFirstHouse[0] = nums[1];
        skipFirstHouse[1] = max(nums[1], nums[2]);

        for(int i = 2; i<n-1; i++){
            skipFirstHouse[i] = max(nums[i+1] + skipFirstHouse[i-2], skipFirstHouse[i-1]);   
        }

        vector<int> skipLastHouse(n-1, INT_MIN);
        skipLastHouse[0] = nums[0];
        skipLastHouse[1] = max(nums[0], nums[1]);

        for(int i = 2; i<n-1; i++){
            skipLastHouse[i] = max(nums[i] + skipLastHouse[i-2], skipLastHouse[i-1]);   
        }

        return max(skipLastHouse[n-2], skipFirstHouse[n-2]); 
    }
};
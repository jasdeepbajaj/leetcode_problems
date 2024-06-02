class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int p = 0;
        for (int i = 0; i < n; i++){
            p^=(i+1);
            p^=nums[i];
        }

        return p;
    }
};
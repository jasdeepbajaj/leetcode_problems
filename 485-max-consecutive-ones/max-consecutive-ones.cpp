class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count1 = 0;
        int max_count = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++){
            if(nums[i] == 1) {
                count1++;
                max_count = max(count1, max_count);
            }
            else{
                count1 = 0;
            }
        }
        return max_count;
    }
};
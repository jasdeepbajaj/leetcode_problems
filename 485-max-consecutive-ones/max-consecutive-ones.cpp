class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int globalCount = 0;

        int localCount = 0;

        for (int i = 0; i<nums.size(); ++i){
            if (nums[i] == 1){
                localCount ++;
                globalCount = max(localCount, globalCount);

            }
            else{
                localCount = 0;
            }
        }

        return globalCount;

    }
};
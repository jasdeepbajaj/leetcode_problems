class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //better solution - using map
        map<int, int> mpp; //element, index
        for(int i = 0; i<nums.size(); ++i){
            int num = nums[i];
            int more = target - num;
            if (mpp.find(more) != mpp.end()){
                return {mpp[more], i};
            }
            mpp[num] = i;
        }

        return {-1,-1};
    }
};
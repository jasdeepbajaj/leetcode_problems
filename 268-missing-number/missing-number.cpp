class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        
        int max_ = INT_MIN;
        int min_ = INT_MAX;

        int sum_actual = 0;
        for(int i = 0; i<n; i++){
            if (nums[i]  > max_) max_ = nums[i];
            if (nums[i] < min_) min_ = nums[i];
            sum_actual += nums[i];
        }
        int sum_should_be = (max_)*(max_ + 1)/2;
        if (min_ != 0) return 0;
        if (sum_actual == sum_should_be ) return max_  + 1;
        else return sum_should_be - sum_actual;
    }
};
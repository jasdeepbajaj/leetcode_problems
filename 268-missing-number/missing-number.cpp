class Solution {
public:
    int missingNumber(vector<int>& nums) {
        //sum_of_all_nums
        int n = nums.size();
        int sum_to_be = n * (n+1) / 2;

        for(int i = 0; i<n; ++i){
            sum_to_be -= nums[i];
        }

        return sum_to_be;
    }
};
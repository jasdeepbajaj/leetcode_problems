class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        int l = 0;
        int current_sum = 0;
        int min_length = INT_MAX;

        // int check_sum  = accumulate(nums.begin(), nums.end(),0);

        // if(check_sum < target){
        //     return 0;
        // }

        for (int r = 0; r < nums.size(); r++){
            current_sum += nums[r];

            while (current_sum >= target){
                min_length = min(min_length, r - l + 1);
                current_sum -= nums[l];
                ++l;
            }
        }

        if(min_length == INT_MAX){
            return 0;
        }

        else{
            return min_length;
        }
        
        
    }
};

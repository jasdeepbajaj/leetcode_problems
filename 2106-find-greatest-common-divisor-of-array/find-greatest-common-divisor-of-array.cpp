class Solution {
public:
    int findGCD(vector<int>& nums) {
        int min_num = INT_MAX;
        int max_num = INT_MIN;
        for (int i =0; i<nums.size(); i++){
            if (nums[i]<min_num) min_num = nums[i];
            if (nums[i]> max_num) max_num = nums[i];
        }
        while(min_num>0 && max_num>0){
            if (min_num>max_num) min_num = min_num%max_num;
            else max_num = max_num%min_num;
        }

        if (min_num == 0) return max_num;
        else return min_num;
    }
};
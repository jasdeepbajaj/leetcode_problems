class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> dict;
        int n = nums.size();
        for (int i = 0; i<n; i++){
            int curr_num = nums[i];
            int more = target - curr_num;
            if (dict.find(more) != dict.end()){
                return {i, dict[more]};
            }
            dict[curr_num] = i;
        }
        return {-1,-1};
    }
};
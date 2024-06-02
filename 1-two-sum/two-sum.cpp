class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> dict; //element, index
        for(int i=0; i<nums.size(); i++){
            int diff_requd = target - nums[i];
            if(dict.find(diff_requd)!=dict.end()){
                return {i, dict[diff_requd]};
            }
            else{
                dict[nums[i]] = i;
            }
        }
        return {};
    }
};
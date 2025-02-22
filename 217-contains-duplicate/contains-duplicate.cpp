class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> dict;

        for(int i = 0; i<nums.size(); i++){
            int num = nums[i];
            if(dict.find(num) != dict.end()) return true;
            dict[num]++;
        }
        return false;
    }
};
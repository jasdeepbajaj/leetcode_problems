class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        map<int, int> hashh; //key = num, value = frequency

        for(int i = 0; i<nums.size(); i++){
            hashh[nums[i]]++;
        }
        nums.clear();
        for(auto pair: hashh){
            nums.push_back(pair.first);
        }
        return nums.size();
    }
};
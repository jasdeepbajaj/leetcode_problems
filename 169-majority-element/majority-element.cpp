class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //using hashing
        map<int, int> dict; //element. count

        for (int i = 0; i<nums.size(); i++){
            dict[nums[i]]++;
        }
        for (auto pair: dict){
            if (pair.second> nums.size()/2) return pair.first;
        }
        return -1;
    }
};
class Solution {

private:
    bool isSorted(vector<int> &sorted_nums){
        for(int i = 0; i<sorted_nums.size()-1; i++){
            int p1 = i;
            int p2 = i+1;
            if (sorted_nums[p1]> sorted_nums[p2]) return false;
        }
        return true;
    }

public:
    bool check(vector<int>& nums) {
        for(int i = 0; i<nums.size(); i++){
            vector<int> sorted_array;
            sorted_array.insert(sorted_array.end(), nums.begin()+i, nums.end());
            sorted_array.insert(sorted_array.end(), nums.begin(), nums.begin()+i);
            if (isSorted(sorted_array)) return true;
        }
        return false;
    }
};
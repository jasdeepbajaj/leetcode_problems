class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int major_el;
        int cnt = 0;

        for (int i = 0; i<nums.size(); ++i){
            if (cnt == 0) {
                major_el = nums[i];
                cnt ++;
            }
            else if (nums[i] == major_el) cnt ++;
            else if (nums[i] != major_el) cnt--;
        }

        return major_el;
        
    }
};
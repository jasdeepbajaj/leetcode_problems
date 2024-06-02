class Solution {
public:
    void sortColors(vector<int>& nums) {
        //dutch national flag algorithm
        // 0 to low-1 - 0 (extreme left)
        //low to mid-1 
        // mid to high - unsorted 0,1,2
        //high + 1, n-1 - 2(extreme right)
        int low = 0;
        int mid = 0;
        int high = nums.size()-1;

        while (mid<=high){
            if (nums[mid] == 0){
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }
            else if (nums[mid] == 1){
                mid++;
            }
            else{
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};
class Solution {
public:
    
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();

        // find the breaking point
        int index = -1;
        for (int i = n-2; i>=0; i--){
            if (nums[i]<nums[i+1]){
                index = i;
                break;
            }
        }

        // If break point does not exist:
        if (index == -1){
            //reverese the whole array
            reverse(nums.begin(), nums.end());
        }

        // Step 2: Find the next greater element and swap it with arr[ind]:
        else{
            for (int i = n-1; i>index;i--){
                if (nums[i] > nums[index]){
                    swap(nums[i], nums[index]);
                    break;
                }

            }
        //reverse after the breaking index
            reverse(nums.begin()+index+1, nums.end());


        }
        




    }
};
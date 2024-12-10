class Solution {
public:
    int missingNumber(vector<int>& nums) {
      // Using XOR
      int n = nums.size();
      int xor1 = 0;
      int xor2 = 0;
    //   for(int i = 0; i<=n;++i){ //[0,3]
    //     xor1 = xor1^i;
    //   } 

    //   for(int num : nums){
    //     xor2 = xor2^num;
    //   }

      for(int i = 0; i<n;++i){ //[0,3)
        xor1 = xor1^i;
        xor2 = xor2^nums[i];
      } 
      xor1 = xor1^n;

      return xor1^xor2;
    }
};
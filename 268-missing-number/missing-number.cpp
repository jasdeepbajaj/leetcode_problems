class Solution {
public:
    int missingNumber(vector<int>& nums) {
      // Using XOR
      int n = nums.size();
      int xor1 = 0;
      for(int i = 0; i<=n;++i){
        xor1 = xor1^i;
      } 

      int xor2 = 0;
      for(int num : nums){
        xor2 = xor2^num;
      }

      return xor1^xor2;
    }
};
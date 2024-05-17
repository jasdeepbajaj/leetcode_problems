class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        n = len(nums)
        for i in range(n):
            if nums[i] <=0 or nums[i] > n:
                nums[i] = -1
        
        if len(nums) == 1 and nums[0] != 1:
            return 1
        

        

        max_num = max(nums)
        if max_num < 1:
            return 1

        ans = [0] * max_num

        for i in range(len(nums)):
            if nums[i]>0:
                ans[nums[i]-1] = nums[i]
        
        if not 0 in ans:
            return (max_num + 1)
        for i in range(len(ans)):
            if ans[i] == 0:
                return i+1

        
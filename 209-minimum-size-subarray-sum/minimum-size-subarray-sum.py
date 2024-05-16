class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        l = 0
        current_sum = 0
        min_length = float('inf')

        if sum(nums) < target:
            return 0

        for r in range(len(nums)):
            current_sum += nums[r]
            
            while current_sum >= target:
                min_length = min(min_length, r - l + 1)
                current_sum -= nums[l]
                l += 1
        
        return min_length

        
        
class Solution:
    def findDuplicates(self, nums: List[int]) -> List[int]:
        n = len(nums)
        ans = [0] * n
        ans_arr = []
        for i in range(n):
            ans[nums[i] - 1] += 1

        for i in range(n):
            if ans[i] > 1:
                ans_arr.append(i+1)

        return ans_arr

        
        
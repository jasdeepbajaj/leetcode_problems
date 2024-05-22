class Solution:
    def findIndices(self, nums: List[int], indexDifference: int, valueDifference: int) -> List[int]:
        minI = float('inf')
        minV = float('inf')
        maxI = -float('inf')
        maxV = -float('inf')
        for j in range(indexDifference, len(nums)):
            i = j - indexDifference
            if nums[i] >= maxV:
                maxV = nums[i]
                maxI = i

            if nums[i] < minV:
                minV = nums[i]
                minI = i

            if abs(nums[j] - maxV) >= valueDifference:
                return [maxI, j]
            
            elif abs(nums[j] - minV) >= valueDifference:
                return [minI, j]

            
        return [-1, -1]

        
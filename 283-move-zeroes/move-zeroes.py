class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        temp = []
        count = 0
        for i in range(len(nums)):
            if nums[i] != 0:
                temp.append(nums[i])
            else:
                count+=1

        for i in range(count):
            temp.append(0)

        for i in range(len(nums)):
            nums[i] = temp[i]
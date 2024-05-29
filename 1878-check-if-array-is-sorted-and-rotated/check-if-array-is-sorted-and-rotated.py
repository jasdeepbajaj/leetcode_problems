class Solution:
    def isSorted(self, array):
        n = len(array)

        for i in range(n-1):
            p1 = i
            p2 = i+1
            if array[p1] > array[p2]:
                return False

        return True
    
    def check(self, nums: List[int]) -> bool:
        for i in range(len(nums)):
            sorted_array = nums[i:len(nums)] + nums[0:i]
            if self.isSorted(sorted_array):
                return True


        return False

        
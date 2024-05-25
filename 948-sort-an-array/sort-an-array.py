class Solution:
    def merge(self, nums, low, mid, high):
        p1 = low
        p2 = mid + 1
        ans = []
        while(p1<=mid and p2<=high):
            if nums[p1]<nums[p2]:
                ans.append(nums[p1])
                p1+=1
            
            else:
                ans.append(nums[p2])
                p2+=1
        
        while p1<=mid:
            ans.append(nums[p1])
            p1+=1

        while p2<=high:
            ans.append(nums[p2])
            p2+=1

        for i in range(len(ans)):
            nums[low + i] = ans[i]

        


    def mergeSort(self,nums, low, high):
        mid = (low + high)//2
        if low < high:
            self.mergeSort(nums, low,  mid)
            self.mergeSort(nums, mid+1, high)

            self.merge(nums, low, mid, high)

        else:
            return
    
    def sortArray(self, nums: List[int]) -> List[int]:
        low = 0
        high = len(nums) - 1
        
        self.mergeSort(nums, low, high)

        return nums
        
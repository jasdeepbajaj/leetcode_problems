class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        p1 = 0
        p2 = 0
        temp = []

        while (p1<m and p2<n):
            if nums1[p1]<nums2[p2]:
                temp.append(nums1[p1])
                p1+=1

            else:
                temp.append(nums2[p2])
                p2+=1

        while p1<m:
            temp.append(nums1[p1])
            p1+=1

        while p2<n:
            temp.append(nums2[p2])
            p2+=1

        for i in range(0, m+n):
            nums1[i] = temp[i]


        
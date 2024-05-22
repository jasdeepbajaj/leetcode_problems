class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        p1, p2 = 0, 0
        m, n = len(nums1), len(nums2)
        
        ans = [0] * (int((m+n)/2) + 1) 
        # print(ans)

        i = 0 
        while i<len(ans):
            if p1 < m and p2 < n:
                if nums1[p1] < nums2[p2]:
                    ans[i] = nums1[p1]
                    i+=1
                    p1+=1
                    # print(ans)

                else:
                    ans[i] = nums2[p2]
                    i+=1
                    p2+=1
                    # print(ans)

            elif p1 == m:
                ans[i] = nums2[p2]
                i+=1
                p2+=1

            else:
                ans[i] = nums1[p1]
                i+=1
                p1+=1
        # print(ans)
        if (m+n)%2 == 0:
            return (ans[-1] + ans[-2])/2

        else:
            return ans[-1]

            
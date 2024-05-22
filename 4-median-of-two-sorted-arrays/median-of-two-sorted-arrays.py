from typing import List

class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        # Initialize pointers for nums1 and nums2
        index1, index2 = 0, 0
        # Get lengths of the two arrays
        len1, len2 = len(nums1), len(nums2)
        
        # Create a new array to store the first half of the merged arrays up to the median point
        merged_half = [0] * (int((len1 + len2) / 2) + 1)

        i = 0
        # Merge arrays until the merged_half array is filled
        while i < len(merged_half):
            if index1 < len1 and index2 < len2:
                # Compare elements of both arrays and add the smaller one to merged_half
                if nums1[index1] < nums2[index2]:
                    merged_half[i] = nums1[index1]
                    index1 += 1
                else:
                    merged_half[i] = nums2[index2]
                    index2 += 1
            # If all elements of nums1 are merged, add remaining elements of nums2
            elif index1 == len1:
                merged_half[i] = nums2[index2]
                index2 += 1
            # If all elements of nums2 are merged, add remaining elements of nums1
            else:
                merged_half[i] = nums1[index1]
                index1 += 1
            i += 1

        # Check if the combined length of nums1 and nums2 is even or odd
        if (len1 + len2) % 2 == 0:
            # If even, return the average of the two middle elements
            return (merged_half[-1] + merged_half[-2]) / 2
        else:
            # If odd, return the middle element
            return merged_half[-1]

class Solution:
    def longestPalindrome(self, s: str) -> int:
        sum_max_palindrome = 0
        ans = {}
        has_odd = False
        for char in s:
            if char in ans:
                ans[char] +=1

            else:
                ans[char] = 1

        for char, freq in ans.items():
            if freq % 2 == 0:
                sum_max_palindrome += freq

            elif freq % 2 == 1:
                sum_max_palindrome  += (freq-1)
                has_odd = True
                
        if has_odd:
            return sum_max_palindrome + 1
        else:    
            return sum_max_palindrome

        
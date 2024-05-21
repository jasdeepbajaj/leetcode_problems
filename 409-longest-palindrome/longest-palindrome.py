class Solution:
    def longestPalindrome(self, s: str) -> int:
        odd_count = 0
        ans = {}
        # has_odd = False
        for char in s:
            if char in ans:
                ans[char] +=1

            else:
                ans[char] = 1
                
            if ans[char] % 2  == 0:
                odd_count -= 1
                
            else:
                odd_count += 1
        print(odd_count)
        if odd_count > 1:
            return len(s) - odd_count + 1
            
        else:
            return len(s)

            
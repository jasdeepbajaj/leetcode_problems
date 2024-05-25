class Solution:
    def mergeAlternately(self, word1: str, word2: str) -> str:
        p1 = 0
        p2 = 0
        ans = ''
        m, n = len(word1), len(word2)
        while (p1<m and p2<n):
            if p1 == p2:
                ans += word1[p1]
                p1+=1

            if p1>p2:
                ans += word2[p2]
                p2+=1
        while p1<m:
            ans += word1[p1]
            p1+=1
        
        while p2<n:
            ans += word2[p2]
            p2+=1

        return ans

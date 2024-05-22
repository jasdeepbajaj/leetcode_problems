class Solution:
    def countPrimes(self, n: int) -> int:
        ans = [0] * n
        for i in range(2,n):
            if ans[i] == 0:
                j = i*i
                while j<n:
                    ans[j] = 1
                    j+=i
                    # print(ans)
        count = 0
        for i in range(2, len(ans)):
            if ans[i] == 0:
                count += 1

        return count

        
        
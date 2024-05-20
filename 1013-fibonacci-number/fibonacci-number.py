class Solution:
    @lru_cache(maxsize=None)
    def fib(self, n: int) -> int:
        ans = [0, 1]

        for i in range(2, n+1):
            ans.append(ans[i-2] + ans[i-1])

        return ans[n]
        
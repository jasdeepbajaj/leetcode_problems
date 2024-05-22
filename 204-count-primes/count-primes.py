class Solution:
    def countPrimes(self, n: int) -> int:
        if n < 2:
            return 0
        
        # Initialize a list to mark non-prime numbers
        is_not_prime = [0] * n
        
        # Iterate from 2 to n-1 to mark non-prime numbers
        for i in range(2, n):
            if is_not_prime[i] == 0:  # If i is a prime number
                # Mark multiples of i starting from i*i as non-prime
                j = i * i
                while j < n:
                    is_not_prime[j] = 1
                    j += i
        
        # Count prime numbers by counting 0s in the is_not_prime list
        # prime_count = 0
        # for i in range(2, len(is_not_prime)):
        #     if is_not_prime[i] == 0:
        #         prime_count += 1
        return n - 2 - sum(is_not_prime)
        # return prime_count

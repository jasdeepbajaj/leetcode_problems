class Solution {
public:
    int countPrimes(int n) {

        // Initialize a count variable to keep track of the number of prime numbers found.
        int count = 0;

        // Vector of boolean values to keep track of prime numbers. 
        // Initially, all numbers are assumed to be prime (true), except for indices 0 and 1.
        vector<bool> check (n+1, true);
        check[0] = check[1] = false; // 0 and 1 are not prime numbers.

        // Loop through all numbers from 2 to n to check for primality.
        for(int i = 2; i < n; i++){
            // If the current number is marked as prime,
            // increment the prime count and mark its multiples as non-prime.
            if(check[i]){
                count++;
                // Mark all multiples of i as non-prime. Starting from i*i because
                // any number less than i*i would have already been marked by smaller primes.
                for(long long j = (long long)i*i; j<n; j+=i){
                    check[j] = false;
                }
            }
        }
        // Return the total count of prime numbers found.
        return count;
    }
};
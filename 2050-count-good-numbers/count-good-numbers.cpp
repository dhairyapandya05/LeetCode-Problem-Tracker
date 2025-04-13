class Solution {
public:
    long long modPow(long long x, long long n, int MOD) {
        x=x%MOD;
        long long N = n; // Avoid overflow for INT_MIN case
        long long ans = 1;

        while (N) {
            if (N % 2) { // If `N` is odd
                ans = (ans * x) % MOD;
            }
            x = (x * x) % MOD; // Square `x`
            N /= 2;            // Halve `N`
        }

        return ans;
    }

    int countGoodNumbers(long long n) {
        int MOD = 1e9 + 7;
        long long even_positions = (n + 1) / 2;
        long long odd_positions = n / 2;

        long long res =
            (modPow(5, even_positions, MOD) * modPow(4, odd_positions, MOD)) %
            MOD;
        return (int)res;
    }
};

class Solution {
public:
    long long modPow(long long x, long long n, int mod) {
        long long ans = 1;
        x = x % mod;

        while (n > 0) {
            if (n % 2 == 1) {
                ans = (ans * x) % mod;
            }
            x = (x * x) % mod;
            n /= 2;
        }
        return ans;
    }

    int countGoodNumbers(long long n) {
        int MOD = 1e9 + 7;
        long long even_positions = (n + 1) / 2;
        long long odd_positions = n / 2;

        long long res = (modPow(5, even_positions, MOD) * modPow(4, odd_positions, MOD)) % MOD;
        return (int)res;
    }
};

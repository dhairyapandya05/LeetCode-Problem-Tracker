class Solution {
public:
    double myPow(double x, int n) {
        long long N = n; // Avoid overflow for INT_MIN case
        double ans = 1.0;
        
        if (N < 0) {
            x = 1.0 / x;  // Invert `x` when `n` is negative
            N = -N;       // Make `N` positive
        }
        
        while (N) {
            if (N % 2) {   // If `N` is odd
                ans *= x;
            }
            x *= x;        // Square `x`
            N /= 2;        // Halve `N`
        }
        
        return ans;
    }
};
